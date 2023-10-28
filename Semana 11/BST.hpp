#ifndef __BST_HPP__
#define __BST_HPP__

#include <functional>
#include <cmath>

using std::function;

template<class T>
class BinarySearchTree {
public:
    BinarySearchTree(function<bool(T,T)> lowerThan, function<bool(T,T)> equalsTo,
        function<void(T)> printValue, function<bool(T,T)> greaterThan):
        _lowerThan(lowerThan), _equalsTo(equalsTo), _printValue(printValue),
        _greaterThan(greaterThan) {
        _root = nullptr;
        _size = 0;
    }
    void insert(T value) {
        _insert(_root, value);
    }
    bool find(T value) {
        return _find(_root, value);
    }
    bool erase(T value) {
        return true;
    }
    void preOrder() {
        _preOrder(_root);
    }
    void inOrder() {
        _inOrder(_root);
    }
    void postOrder() {
        _postOrder(_root);
    }
    size_t size() {
        return _size;
    }
    int height() {
        return _height(_root);
    }
    T lowestCommonAncestor(T a, T b) {
        if(!(iterativeFind(a) && iterativeFind(b))) {
            throw "Some or both of these values do not exist";
        }
        return _lowestCommonAncestor(_root, a, b);
    }
    bool iterativeFind(T value) {
        Node* aux = _root;
        while(aux) {
            if(_equalsTo(aux->value, value)) return true;
            if(_lowerThan(value, aux->value)) aux = aux->left;
            else aux = aux->right;
        }
        return false;
    }
private:
    class Node {
    public:
        T value;
        Node* left;
        Node* right;
    };
    Node* _root;
    size_t _size;
    // bool (*_lowerThan)(T,T);
    function<bool(T,T)> _lowerThan;
    function<bool(T,T)> _greaterThan;
    function<bool(T,T)> _equalsTo;
    function<void(T)> _printValue;
private:
    void _insert(Node*& n, T value) {
        if(!n) {
            n = new Node{value, nullptr, nullptr};
            ++_size;
            return;
        }
        if(_lowerThan(value, n->value)) _insert(n->left, value);
        else _insert(n->right, value);
    }
    bool _find(Node* n, T value) {
        if(!n) return false;
        if(_equalsTo(n->value, value)) return true;
        if(_lowerThan(value, n->value)) return _find(n->left, value);
        else return _find(n->right, value);
    }
    void _preOrder(Node* n) {
        // MUESTRO EL VALOR DEL NODO - VOY POR HIJO IZQUIERDO - VOY POR HIJO DERECHO
        if(!n) return;
        _printValue(n->value); // MUESTRO EL VALOR DEL NODO
        _preOrder(n->left); // VOY POR HIJO IZQUIERDO
        _preOrder(n->right); // VOY POR HIJO DERECHO
    }
    void _inOrder(Node* n) {
        // VOY POR HIJO IZQUIERDO - MUESTRO EL VALOR DEL NODO - VOY POR HIJO DERECHO
        if(!n) return;
        _inOrder(n->left); // VOY POR HIJO IZQUIERDO
        _printValue(n->value); // MUESTRO EL VALOR DEL NODO
        _inOrder(n->right); // VOY POR HIJO DERECHO
    }
    void _postOrder(Node* n) {
        // VOY POR HIJO IZQUIERDO - VOY POR HIJO DERECHO - MUESTRO EL VALOR DEL NODO
        if(!n) return;
        _postOrder(n->left); // VOY POR HIJO IZQUIERDO
        _postOrder(n->right); // VOY POR HIJO DERECHO
        _printValue(n->value); // MUESTRO EL VALOR DEL NODO
    }
    int _height(Node* n) {
        if(!n) return -1;
        return std::max(_height(n->left), _height(n->right)) + 1;
    }
    T _lowestCommonAncestor(Node* n, T a, T b) {
        if(_lowerThan(a, n->value) && _lowerThan(b, n->value)) {
            return _lowestCommonAncestor(n->left, a, b);
        }
        if(_greaterThan(a, n->value) && _greaterThan(b, n->value)) {
            return _lowestCommonAncestor(n->right, a, b);
        }
        return n->value;
    }
};

#endif