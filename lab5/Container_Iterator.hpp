#pragma once
#include <iostream>
#include <stdexcept>
#include <memory>

template <typename T>
class CustomStack {
public:
    using value_type = T;
    using allocator_type = std::allocator<T>;
    using size_type = std::size_t;

private:
    struct Node {
        value_type* data;
        Node* next;
        Node(value_type* value) : data(value), next(nullptr) {}
    };

public:
    class iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        iterator(Node* node) : currentNode(node) {}

        iterator& operator++() {
            if (currentNode != nullptr) {
                currentNode = currentNode->next;
            }
            return *this;
        }

        iterator operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const iterator& other) const {
            return currentNode == other.currentNode;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

        reference operator*() const {
            return *(currentNode->data);
        }

        pointer operator->() const {
            return currentNode->data;
        }

    private:
        Node* currentNode;
    };

    using const_iterator = iterator;

    CustomStack() : head(nullptr), stackSize(0) {}

    void push(const value_type& value) {
        value_type* newValue = allocator.allocate(1);
        allocator.construct(newValue, value);
        Node* newNode = nodeAllocator.allocate(1);
        newNode->data = newValue;
        newNode->next = head;
        head = newNode;
        ++stackSize;
    }
    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        Node* temp = head;
        head = head->next;
        allocator.destroy(temp->data);
        allocator.deallocate(temp->data, 1);
        nodeAllocator.deallocate(temp, 1);
        --stackSize;
    }

    value_type& top() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return *(head->data);
    }

    const value_type& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return *(head->data);
    }
    bool empty() const {
        return stackSize == 0;
    }

    size_type size() const {
        return stackSize;
    }

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator cbegin() const {
        return const_iterator(head);
    }

    const_iterator cend() const {
        return const_iterator(nullptr);
    }



private:
    Node* head;
    size_type stackSize;
    allocator_type allocator;
    typename allocator_type::template rebind<Node>::other nodeAllocator;
};
