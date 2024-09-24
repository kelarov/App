add_library(utils)
target_sources(utils
    PRIVATE
        utils-impl.cc
    PUBLIC
    FILE_SET CXX_MODULES
    FILES
        utils.cppm)

target_link_libraries(utils PRIVATE fmt::fmt)

