# >> App
cmake_minimum_required(VERSION 3.26.3)


# >> VCPKG MANIFEST FEATURES SETUP
option(BUILD_SAMPLES "Build samples" ON)
if(BUILD_SAMPLES)
  list(APPEND VCPKG_MANIFEST_FEATURES "samples")
endif()

option(BUILD_TESTS "Build tests" ON)
if(BUILD_TESTS)
  list(APPEND VCPKG_MANIFEST_FEATURES "tests")
endif()

# >> DEFINES App AS A C++ PROJECT
project("App" VERSION 0.1.0 LANGUAGES CXX)

# >> SETS AND REQUIRES THE C++ STANDARD TO BE USED
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# >> INCLUDE CUSTOM CMAKE MODULES
include(cmake/msvc_modules_enabler.cmake)
include(cmake/docs.cmake)

# >> AUTO CREATES A BUILD_TESTING OPTION; BUILD_TESTS CONTROLS GTEST THOUGH.
include(CTest)

# >> ADDS LIBRARY, SAMPLES AND TESTS
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)
