
# install vector class library (vcl)
include(ExternalProject)


ExternalProject_Add(vcl 
    GIT_REPOSITORY https://github.com/vectorclass/version2.git
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(vcl SOURCE_DIR)
include_directories(${SOURCE_DIR})
