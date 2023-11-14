#include <gtest/gtest.h>
#include "Money.hpp"
#include <string>

// Constructor

TEST(constructor_test01, default_constructor)
{
    Money a = Money();

    ASSERT_EQ(a.get_size(), 1);
}

TEST(constructor_test02, initializer_list_constructor)
{
    Money a {'1','1','1','1','1'};

    ASSERT_EQ(a.get_size(), 5);
}

TEST(constructor_test03, string_constructor)
{
    std::string str = "11111";
    Money a = Money(str);

    ASSERT_EQ(a.get_size(), 5);
}

TEST(constructor_test04, copy_constructor)
{
    Money first {'1','1','1','1','1'};
    Money second = Money(first);

    ASSERT_EQ(second.get_size(), 5);
}

TEST(constructor_test05, rvalue_constructor)
{
    Money a = {"11111"};

    ASSERT_EQ(a.get_size(), 5);
}

// Operators testing
TEST(o_test01, basic_test_set)
{
    Money a {"001"};
    Money b {'1'};
    Money c {"101"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test02, basic_test_set)
{
    Money a {"00005"};
    Money b {"00005"};
    Money c {"000001"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test03, basic_test_set)
{
    Money a {"1111"};
    Money b {"19"};
    Money c {"2021"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test04, basic_test_set)
{
    Money a {'0'};
    Money b {"12345"};
    Money c {"12345"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test05, basic_test_set)
{
    Money a {"990001"};
    Money b {'1'};
    Money c {"001001"};
    ASSERT_TRUE(c.equals(a.add(b)));
}

TEST(o_test06, basic_test_set)
{
    Money a {"1"};
    Money b {"005"};
    try{
        a.remove(b);
    }catch(std::exception &ex){
        EXPECT_STREQ(ex.what(),"negative balance");
    }
}

TEST(o_test07, basic_test_set)
{
    Money a {"00511"};
    Money b {"0051"};
    Money c {"00001"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(o_test08, basic_test_set)
{
    Money a {"001"};
    Money b {'1'};
    Money c {"99"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(o_test09, basic_test_set)
{
    Money a {"123456"};
    Money b {"123456"};
    Money c {'0'};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

TEST(o_test10, basic_test_set)
{
    Money a {"000000001"};
    Money b {'1'};
    Money c {"99999999"};
    ASSERT_TRUE(c.equals(a.remove(b)));
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}