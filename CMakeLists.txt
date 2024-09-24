cmake_minimum_required(VERSION 3.30.3)

project(MyApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(deps/dependencies)

add_subdirectory(src ${CMAKE_BINARY_DIR}/bin)

