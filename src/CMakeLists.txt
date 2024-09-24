add_executable(myapp main.cc)
target_link_libraries(myapp PRIVATE maths)


add_subdirectory(lib/maths)
add_subdirectory(lib/utils)
