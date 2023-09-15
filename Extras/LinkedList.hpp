#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

template<class T>
class LinkedList {
public:
    LinkedList() = delete;
    virtual void pushBack(T value) = 0;
    virtual void pushFront(T value) = 0;
    virtual void popBack() = 0;
    virtual void popFront() = 0;
    virtual void eraseAt(int index) = 0;
    virtual void print() = 0;
protected:
    class Node {
    public:
        virtual T getValue() = 0;
        virtual Node* getNext() { return nullptr; }
        virtual Node* getBack() { return nullptr; }
    }
};
#endif