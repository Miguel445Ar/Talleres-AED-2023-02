#ifndef __COLA_HPP__
#define __COLA_HPP__

#include "DLL.hpp"

template<class T>
class Queue: public DoublyLinkedList<T> {
public:
    Queue(std::function<void(T)> show): DoublyLinkedList<T>(show) {}
    ~Queue() {}
    void push(T value) {
        this->pushBack(value);
    }
    T pop() {
        T value = top();
        this->popBack();
        return value;
    }
    T eraseAtPosition(int pos) {
        T value = getAtPosition(pos);
        this->eraseAt(pos);
        return value;
    }
    void insertAtPosition(T value, int pos) {
        this->insertAt(value, pos);
    }
    T getAtPosition(int pos) {
        return this->getAt(pos);
    }
    size_t Size() {
        return this->size();
    }
    T head() {
        return this->_start->value;
    }
    T top() {
        return this->_end->value;
    }
};

#endif