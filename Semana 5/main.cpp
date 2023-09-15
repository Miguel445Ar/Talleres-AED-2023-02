#include <iostream>
#include "MinStack.hpp"

struct Node {
    int value;
    Node* next;
};

int getKthFromEndOfListIterative(Node* head, int k) {
    Node* aux = head;
    int n = 0;
    while(aux != nullptr) {
        aux = aux->next;
        ++n;
    }
    int pos = n - k;
    if(pos < 0) return (int)-1000000;
    for(int i = 0; i < pos; ++i) head = head->next;
    return head->value;
}

int getKthFromEndOfListRecursive(Node* head, int k) {
    static bool elementWasFound = false;
    static Node* startOfList = head;
    if(head == nullptr) return k - 1;
    int res = getKthFromEndOfListRecursive(head->next, k);
    if(elementWasFound) return res;
    if(res == 0) {
        elementWasFound = true;
        return head->value;
    }
    if(head == startOfList)
        return -10000000000;
    return res - 1;
}



int main() {
    // 7 - 8 - 4 - 2 - 5 - 9
    // MinStack<int> minStack([](int a, int b) -> bool { return a < b;});
    // minStack.push(-2);
    // minStack.push(0);
    // minStack.push(-3);
    // std::cout << "\n Min is" << minStack.getMin() << "\n"; // return -3
    // minStack.pop();
    // std::cout << "\n Top is" << minStack.top() << "\n";    // return 0
    // std::cout << "\n Min is" << minStack.getMin() << "\n"; // return -2
    Node* head = new Node{7, nullptr};
    head->next = new Node{8, nullptr};
    head->next->next = new Node{4, nullptr};
    head->next->next->next = new Node{2, nullptr};
    head->next->next->next->next = new Node{5, nullptr};
    head->next->next->next->next->next = new Node{9, nullptr};

    std::cout << "\n3rd Element from end of list (Iterative) " << getKthFromEndOfListIterative(head, 3) << "\n";
    std::cout << "\n3rd Element from end of list (Recursive) " << getKthFromEndOfListRecursive(head, 3) << "\n";
    return 0;
}