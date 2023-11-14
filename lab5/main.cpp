#include <iostream>
#include <map>
#include <vector>
#include "Container_Iterator.hpp"
int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main() {
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>>> myMapAllocator;
     for (int i = 0; i < 10; ++i) {
        myMapAllocator.emplace(i, factorial(i));
    }

    // Вывод значений на экран
    for (const auto& pair : myMapAllocator) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    MyAllocator<int> allocator;
    int* ptr = allocator.allocate(3); // выделение памяти под 3 элемента

    // Заполнение памяти элементами
    for (int i = 0; i < 3; ++i) {
        ptr[i] = i;
    }

    int* new_ptr = allocator.allocate(6); // перевыделение памяти на 6 элементов

    // Проверка, что данные из ptr были успешно перенесены в new_ptr
    for (int i = 0; i < 3; ++i) {
        std::cout << ptr[i] << " " << new_ptr[i] << std::endl;
    }

    allocator.deallocate(ptr, 3); // освобождение старой памяти
    allocator.deallocate(new_ptr, 6);

    MyStack<int> myStack;
    // Добавление элементов в стек и вывод их содержимого
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    // Использование итератора для перебора элементов стека
    for (auto it = myStack.begin(); it != myStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Использование константного итератора для перебора элементов стека
    const MyStack<int>& constStack = myStack;
    MyStack<int>::ConstIterator cit = constStack.cbegin();
    while (cit != constStack.cend()) {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;


    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }


    return 0;
}