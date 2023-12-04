#include <gtest/gtest.h>
#include "box_capacity.h"

TEST(test_01, basic_tests)
{
    ASSERT_TRUE(box_capacity(32, 64, 16)==13824);
}

TEST(test_02, basic_tests)
{
    ASSERT_TRUE(box_capacity(64, 16, 32)==13824);
}
TEST(test_03, basic_tests)
{
    ASSERT_TRUE(box_capacity(-2, 18, 32)==-1);
}
TEST(test_04, basic_tests)
{
    ASSERT_TRUE(box_capacity(1, 64, 32)==0);
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
