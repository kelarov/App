add_library(utils_md)
target_sources(utils_md PRIVATE
               FILE_SET cxx_modules
               TYPE CXX_MODULES
               FILES
               utils.ixx
               partitions/utils-print.ixx
               partitions/utils-helloworld.ixx
               partitions/utils-mynumber.ixx)

# PS: you could also use BASE_DIRS to control this directory-ey thing
# I chose to keep it simple though
