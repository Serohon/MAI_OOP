#include <gtest/gtest.h>
#include "Trapezoid.cpp"
#include "Rhombus.cpp"
#include "Pentagon.cpp"

#include <string>

// Constructor

TEST(Trap, geo_center_trap)
{
    Trapezoid Trapezoid_ (23, 12, 45);
    ASSERT_EQ(Trapezoid_.print_geometric_center(), 17.5);
}

TEST(Trap, area_test)
{
    Trapezoid Trapezoid_(23, 12, 45);

    ASSERT_EQ(Trapezoid_.operator double(), 787.5);
}

TEST(Trap, test_of_trap)
{
    ASSERT_THROW(Trapezoid (23, 12, -2), std::invalid_argument);
}

TEST(Trap, equalsTrap)
{
    Trapezoid Trapezoid_(23, 11, 44);
    Trapezoid Trapezoidi(23, 11, 44);
    ASSERT_TRUE(Trapezoid_ == Trapezoidi);
}

TEST(Rhomb, geo_center_rhomb)
{
    Rhombus Rhombus_(1, 1, 2, 2, 3, 3, 4, 4);
    ASSERT_EQ(Rhombus_.print_geometric_center(), 2.5);
}

TEST(Rhomb, area_rhomb)
{
    Rhombus Rhombus_(1, 1, 2, 2, 3, 3, 4, 4);
    ASSERT_DOUBLE_EQ(Rhombus_.operator double(), 4.0);
}

TEST(Rhomb, equals_rhomb)
{
    Rhombus Rhombusi(1, 1, 2, 2, 3, 3, 4, 4);
    Rhombus Rhombus_(1, 1, 2, 2, 3, 3, 4, 4);
    ASSERT_TRUE(Rhombusi == Rhombus_);
}

TEST(Pentag, area_pentag)
{
    Pentagon Pentagon_(5);

    ASSERT_NEAR(Pentagon_.operator double(), 43.0119, 10e-5);
}

TEST(Pentag, geo_center_pentag)
{
    Pentagon Pentagon_(5);

    ASSERT_NEAR(Pentagon_.print_geometric_center(), 3.44095, 10e-5);
}

TEST(Pentag, check_pentag)
{
    ASSERT_THROW(Pentagon(-2), std::invalid_argument);
}

TEST(Pentag, equals_pentag)
{
    Pentagon Pentagon_(5);
    Pentagon Pentagoni(5);
    ASSERT_TRUE(Pentagon_ == Pentagoni);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}