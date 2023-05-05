#include <gtest/gtest.h>

import utils;

TEST(EnvironmentTest, GTestIsCorrectlyLinked) {
	ASSERT_EQ(42, 42);
};


TEST(UtilsTests, UtilsLinkWithGtestWorks) {
	ASSERT_EQ(utty::my_int(true), 1234);
};


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
