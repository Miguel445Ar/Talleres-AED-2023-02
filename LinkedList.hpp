#ifndef __LINKED_LIST_HPP__
#define __LINKED_LIST_HPP__

template<class T>
class LinkedList {
public:
    LinkedList() {
        _start = _end = nullptr;
        _size = 0;
    }
    ~LinkedList() {

    }
    void pushBack(T value) {
        Node* newNode = new Node{nullptr, value};
        if(isEmpty()) {
            _start = _end = newNode;
            ++_size;
            return;
        }
        _end->next = newNode;
        _end = newNode;
        ++_size;
    }
    void reverse() {
        Node* result = _reverse(_start);
        result->next = nullptr;

        Node* aux = _start;
        _start = _end;
        _end = aux;
    }
    bool isEmpty() {
        return _size == 0;
    }
    void print(void (*ptr)(T)) {
        Node* aux = _start;
        while(aux) {
            ptr(aux->value);
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
private:
    Node* _reverse(Node* node) {
        if(node->next == nullptr) return node;
        Node* n = _reverse(node->next);
        n->next = node;
        return node;
    }
};

#endif