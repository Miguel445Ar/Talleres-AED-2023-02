#ifndef __STACK_HPP__
#define __STACK_HPP__

template<class T>
class Stack {
public:
    Stack() {
        _start = _end = nullptr;
        _size = 0;
    }
    ~Stack() {
        while(!isEmpty()) pop();
    }
    void push(T value) {
        Node* newNode = new Node{nullptr, value};
        if(isEmpty()) {
            _start = _end = newNode;
            ++_size;
            return;
        }
        newNode->next = _start;
        _start = newNode;
        ++_size;
    }
    bool isEmpty() {
        return _size == 0;
    }
    T top() {
        if(isEmpty()) throw "You cannot return a top from empty list";
        return this->_start->value;
    }
    void pop() {
        if(isEmpty()) throw "You cannot pop from empty list";
        if(_size == 1) {
            delete _end;
            _start = _end = nullptr;
            _size = 0;
            return;
        }
        Node* nodeToDelete = _start;
        _start = _start->next;
        delete nodeToDelete;
        --_size;
    }
    void print() {
        Node* aux = _start;
        while(aux) {
            std::cout << aux->value << "-->";
            aux = aux->next;
        }
    }
private:
    class Node {
    public:
        Node* next;
        T value;
    };
    Node* _start;
    Node* _end;
    size_t _size;
};

#endif