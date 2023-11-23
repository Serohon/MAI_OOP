#include <iostream>
#include <list>
#pragma once
template <typename T>
class MyAllocator {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    template <typename U>
    struct rebind {
        using other = MyAllocator<U>;
    };

    MyAllocator() {}

    T* allocate(size_type n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }
    
    void deallocate(T* p, size_t n) noexcept {
        ::operator delete(p);
    }
private:
    std::list<T*> memoryBlocks;
};
