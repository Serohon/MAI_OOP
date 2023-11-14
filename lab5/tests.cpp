#include <gtest/gtest.h>
#include "Container_Iterator.hpp"

// Тестирование добавления элементов в контейнер
TEST(MyStackTest, PushElements) {
    MyStack<int> myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    ASSERT_EQ(myStack.size(), 3);
}

TEST(MyStackTest, TopTest) {
    MyStack<int> myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    ASSERT_EQ(myStack.top(), 15);
}

TEST(MyStackTest, PopTest) {
    MyStack<int> myStack;
    myStack.push(15);
    myStack.push(10);
    myStack.push(5);
    myStack.pop();
    myStack.pop();
    ASSERT_EQ(myStack.size(), 1);
}

// Тестирование вывода элементов через итератор
TEST(MyStackTest, IteratorTest1) {
    MyStack<int> myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    int expected_output = 5; // ожидаемый вывод в обратном порядке

    MyStack<int>::Iterator it = myStack.begin();
    ASSERT_EQ(*it, expected_output);
}

TEST(MyStackTest, IteratorTest2) {
    MyStack<int> myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    int expected_output = 750; 
    MyStack<int>::Iterator it = myStack.begin();
    int ans = 1;
    while (it != myStack.end()) {
        ans *= *it;
        ++it;
    }

    ASSERT_EQ(ans, expected_output);
}

// Тестирование работы аллокатора
TEST(MyAllocatorTest, AllocateMemory) {
    MyAllocator<int> allocator;
    int* ptr = allocator.allocate(5); // выделение памяти под 5 элементов

    ASSERT_NE(ptr, nullptr);

    allocator.deallocate(ptr, 5); // освобождение памяти
}

// Тестирование переноса данных при перевыделении памяти
TEST(MyAllocatorTest, ReallocateMemory) {
    MyAllocator<int> allocator;
    int* ptr = allocator.allocate(3); // выделение памяти под 3 элемента

    // Заполнение памяти элементами
    for (int i = 0; i < 3; ++i) {
        ptr[i] = i;
    }

    int* new_ptr = allocator.allocate(6); // перевыделение памяти на 6 элементов

    for (int i = 0; i < 3; ++i) {
        ASSERT_NE(ptr[i], new_ptr[i]);
    }

    allocator.deallocate(ptr, 3); // освобождение старой памяти
    allocator.deallocate(new_ptr, 6); // освобождение новой памяти
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
