project(BenchProject)

include(ExternalProject)

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(benchmark 
    GIT_REPOSITORY https://github.com/google/benchmark
    CMAKE_ARGS 
              -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} 
              -DBENCHMARK_ENABLE_GTEST_TESTS=OFF
              -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
)

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

file(GLOB APP_SOURCES ${CMAKE_SOURCE_DIR}/src/*.h)
file(GLOB TEST_SOURCES ${CMAKE_SOURCE_DIR}/benchmarks/*.cpp ${CMAKE_SOURCE_DIR}/benchmarks/*.h)

add_executable(bench ${APP_SOURCES} ${TEST_SOURCES})
add_dependencies(bench benchmark)
target_link_libraries(bench libbenchmark.a )
target_link_libraries(bench pthread)
