#include <gtest/gtest.h>
#include "Container_Iterator.hpp"
#include "Allocator.hpp"
// Тестирование добавления элементов в контейнер
TEST(CustomStackTest, PushElements) {
    CustomStack<int> CustomStack;
    CustomStack.push(5);
    CustomStack.push(10);
    CustomStack.push(15);

    ASSERT_EQ(CustomStack.size(), 3);
}

TEST(CustomStackTest, TopTest) {
    CustomStack<int> CustomStack;
    CustomStack.push(5);
    CustomStack.push(10);
    CustomStack.push(15);

    ASSERT_EQ(CustomStack.top(), 15);
}

TEST(CustomStackTest, PopTest) {
    CustomStack<int> CustomStack;
    CustomStack.push(15);
    CustomStack.push(10);
    CustomStack.push(5);
    CustomStack.pop();
    CustomStack.pop();
    ASSERT_EQ(CustomStack.size(), 1);
}

// Тестирование вывода элементов через итератор
TEST(CustomStackTest, IteratorTest1) {
    CustomStack<int> CustomStack;
    CustomStack.push(1);
    CustomStack.push(2);
    CustomStack.push(3);
    int expected_output = 3;
    for (auto it = CustomStack.begin(); it != CustomStack.end(); ++it){
        ASSERT_EQ(*it, expected_output--);
    }
}

TEST(CustomStackTest, IteratorTest2) {
    CustomStack<int> CustomStack;
    CustomStack.push(5);
    CustomStack.push(11);
    CustomStack.push(15);

    int expected_output = 825; 
    int ans = 1;
    for(auto it = CustomStack.begin(); it != CustomStack.end(); ++it) {
        ans *= *it;
    }
    ASSERT_EQ(ans, expected_output);
}

// Тестирование работы аллокатора
TEST(MyAllocatorTest, AllocateMemory) {
    MyAllocator<int> allocator;
    int* ptr = allocator.allocate(5);

    ASSERT_NE(ptr, nullptr);

    allocator.deallocate(ptr, 5);
}

TEST(MyAllocatorTest, DeallocateMemory) {
    MyAllocator<int> allocator;
    int* ptr = allocator.allocate(5);

    allocator.deallocate(ptr, 5);
    ASSERT_NE(ptr, nullptr);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
