add_library(maths)
target_sources(maths
    PUBLIC
    FILE_SET CXX_MODULES
    FILES
        math.cppm
        math-add.cppm
        math-mult.cppm)

target_link_libraries(maths PRIVATE utils)

