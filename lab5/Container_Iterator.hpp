#include <iostream>
#include <list>
#include "Allocator.hpp"
// Собственный контейнер (стек) с использованием std::list и аллокатора
template <typename T, typename Alloc = MyAllocator<T>>
class MyStack {
public:
    using value_type = T;
    using allocator_type = Alloc;
    using size_type = typename Alloc::size_type;

    MyStack() {}

    void push(const T& value) {
        data_.push_back(value);
    }

    void pop() {
        if (!data_.empty()) {
            data_.pop_back();
        }
    }

    T& top() {
        if (!data_.empty()) {
            return data_.back();
        }
        throw std::out_of_range("Stack is empty");
    }

    bool empty() const {
        return data_.empty();
    }

    size_type size() const {
        return data_.size();
    }
     class Iterator {
    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

        Iterator(typename std::list<T, Alloc>::iterator iter) : iter_(iter) {}

        reference operator*() const {
            return *iter_;
        }

        pointer operator->() const {
            return &(*iter_);
        }

        Iterator& operator++() {
            ++iter_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return iter_ == other.iter_;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

    private:
        typename std::list<T, Alloc>::iterator iter_;
    };

    Iterator begin() {
        return Iterator(data_.begin());
    }

    Iterator end() {
        return Iterator(data_.end());
    }

    // Константный итератор
    class ConstIterator {
    public:
        using value_type = const T;
        using reference = const T&;
        using pointer = const T*;
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;

        ConstIterator(typename std::list<T, Alloc>::const_iterator iter) : iter_(iter) {}

        reference operator*() const {
            return *iter_;
        }

        pointer operator->() const {
            return &(*iter_);
        }

        ConstIterator& operator++() {
            ++iter_;
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const ConstIterator& other) const {
            return iter_ == other.iter_;
        }

        bool operator!=(const ConstIterator& other) const {
            return !(*this == other);
        }

    private:
        typename std::list<T, Alloc>::const_iterator iter_;
    };

    ConstIterator cbegin() const {
        return ConstIterator(data_.cbegin());
    }

    ConstIterator cend() const {
        return ConstIterator(data_.cend());
    }

private:
    std::list<T, Alloc> data_;
};
