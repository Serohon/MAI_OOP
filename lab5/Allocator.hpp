#include <iostream>
#include <map>
#include <vector>
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

    MyAllocator(size_type block_size = 10) noexcept : block_size_(block_size){}

    T* allocate(size_type n) {
        if (n > block_size_) {
            throw std::bad_alloc();
        }
        return reinterpret_cast<T*>(::operator new(n * sizeof(T)));
    }
    
    void deallocate(T* p, size_type n) noexcept {
        ::operator delete(p);
    }
private:
    size_type block_size_;
    T* _buffer;
};
