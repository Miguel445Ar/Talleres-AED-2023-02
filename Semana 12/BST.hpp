#ifndef __BST_HPP__
#define __BST_HPP__

#include <functional>
#include <cmath>
#include <algorithm>

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
    int height() {
        return getHeight(this->_root);
    }
    size_t size() {
        return _size;
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
        int height;
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
            n = new Node{value, nullptr, nullptr, 0};
            ++_size;
            return;
        }
        if(_lowerThan(value, n->value)) _insert(n->left, value);
        else _insert(n->right, value);
        balanceSubTree(n);
        updateHeight(n);
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
    void updateHeight(Node* n) {
        int newHeight = std::max((n->left)?n->left->height: -1,(n->right)?n->right->height: -1) + 1;
        n->height = newHeight;
    }
    int getHeight(Node* n) {
        return n ? n->height: -1;
    }
    void leftRotation(Node*& n) {
        Node* nRight = n->right;
        n->right = nRight->left;
        nRight->left = n;
        updateHeight(n);
        updateHeight(nRight);
        n = nRight;
    }
    void rightRotation(Node*& n) {
        Node* nLeft = n->left;
        n->left = nLeft->right;
        nLeft->right = n;
        updateHeight(n);
        updateHeight(nLeft);
        n = nLeft;
    }
    void balanceSubTree(Node*& n) {
        int heightDiff = getHeight(n->left) - getHeight(n->right);
        // Desbalanceado por la derecha
        if(heightDiff <= -2) {
            if(n->right->right == nullptr) {
                // Rotacion Compuesta -> DER - IZQ
                rightRotation(n->right);
                leftRotation(n);
                return;
            }
            // Rotacion Izquierda
            leftRotation(n);
            return;
        }
        if(heightDiff >= 2) { // Desbalanceado por la izquierda
            if(n->left->left == nullptr) {
                // Rotacion Compuesta -> IZQ - DER
                leftRotation(n->left);
                rightRotation(n);
                return;
            }
            // Rotacion Derecha
            rightRotation(n);
            return;
        }
    }
};

#endif