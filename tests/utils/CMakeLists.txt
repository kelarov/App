add_executable(utils_tests tests_utils.cpp)
target_link_libraries(utils_tests PRIVATE
                      GTest::gtest
                      GTest::gtest_main
                      GTest::gmock
                      GTest::gmock_main
                      utils_md)
gtest_discover_tests(utils_tests)

#add_test(ALL_UTILS_TEST utils_tests)
