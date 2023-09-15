#ifndef __MIN_STACK__
#define __MIN_STACK__

#include "Stack.hpp"
#include <functional>
#include <memory>

template<class T>
class MinStack {
public:
    MinStack(std::function<bool(T,T)> isLowerThan):
        _isLowerThan(isLowerThan) {
        // _stack = std::make_unique(Stack<T>());
        // _historyStack = std::make_unique(Stack<T>());
        _stack = new Stack<T>();
        _stack = new Stack<T>();
    }
    ~MinStack() {
        delete _stack;
        delete _historyStack;
    }
    
    void push(T val) {
        if(_stack->isEmpty()){
            _stack->push(val);
            _historyStack->push(val);
            return;
        }
        T lastMin = _historyStack->top();
        if(_isLowerThan(val, lastMin)) _historyStack->push(val);
        else _historyStack->push(lastMin);
        _stack->push(val);
    }
    
    void pop() {
        _stack->pop();
        _historyStack->pop();
    }
    
    T top() {
        return _stack->top();
    }
    
    T getMin() {
        return _historyStack->top();
    }
    void print() {
        _stack->print();
    }
private:
    // std::unique_ptr<Stack<T>> _stack;
    // std::unique_ptr<Stack<T>> _historyStack;
    Stack<T>* _stack;
    Stack<T>* _historyStack;
    std::function<bool(T,T)> _isLowerThan;
};


#endif