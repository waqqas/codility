cmake_minimum_required(VERSION 3.10)
project(app)


include_directories("${CMAKE_SOURCE_DIR}/src")

# Enable for use with clang-tidy.
if(NOT CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

string(TOUPPER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE)

set(CMAKE_C_STANDARD 11)
# Emits -std=gnu++1z on OSX which is not working as expected.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)

set(COMMON_WARN "-Wall -Werror -Wextra -Wstrict-aliasing=2 -Wno-unused-parameter -Wno-unused-variable")
set(COMMON_C_FLAGS "-fstrict-aliasing -fvisibility=hidden")
set(COMMON_CXX_FLAGS "${COMMON_C_FLAGS} -faligned-new -fno-rtti")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(COMMON_WARN "${COMMON_WARN} -Wno-implicit-fallthrough -Wno-psabi")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_C_FLAGS} ${COMMON_WARN}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_CXX_FLAGS} ${COMMON_WARN} -fno-enforce-eh-specs -fnothrow-opt")
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMMON_C_FLAGS} ${COMMON_WARN}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMMON_CXX_FLAGS} ${COMMON_WARN}")
endif()
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS}")


# Add cppcheck target if tool is available.
find_program(CPPCHECK cppcheck HINTS "${TOOLBOX_TOOLCHAIN}/bin")
if (CPPCHECK)
  message(STATUS "Found cppcheck")
  cmake_host_system_information(RESULT CORE_COUNT QUERY NUMBER_OF_LOGICAL_CORES)
  configure_file("${PROJECT_SOURCE_DIR}/cppcheck.sh.in"
    "${CMAKE_BINARY_DIR}/cppcheck.sh" @ONLY)
  add_custom_target(cppcheck COMMAND bash "${CMAKE_BINARY_DIR}/cppcheck.sh")
endif()

# Add clang-format target if tool is available.
find_program(CLANG_FORMAT clang-format HINTS "${TOOLBOX_TOOLCHAIN}/bin")
if (CLANG_FORMAT)
  message(STATUS "Found clang-format")
  configure_file("${PROJECT_SOURCE_DIR}/clang-format.sh.in"
    "${CMAKE_BINARY_DIR}/clang-format.sh" @ONLY)
  add_custom_target(clang-format COMMAND bash "${CMAKE_BINARY_DIR}/clang-format.sh")
endif()

# Add clang-tidy target if tool is available.
find_program(CLANG_TIDY run-clang-tidy.py HINTS "/usr/share/clang/"
  "${TOOLBOX_TOOLCHAIN}/share/clang")
if (CLANG_TIDY)
  message(STATUS "Found clang-tidy")
  cmake_host_system_information(RESULT CORE_COUNT QUERY NUMBER_OF_LOGICAL_CORES)
  add_custom_target(clang-tidy COMMAND "${CLANG_TIDY}"
        -quiet
        -p "${CMAKE_BINARY_DIR}")
endif()

file(GLOB SOURCES src/*.cpp src/*.h)
add_executable(app ${SOURCES})

add_subdirectory(benchmarks)
add_subdirectory(tests)