#include <iostream>
#include "BST.hpp"

int main() {
    BinarySearchTree<int> bst(
        [](int a, int b) -> bool { return a < b;},
        [](int a, int b) -> bool { return a == b; },
        [](int a) -> void { std::cout << a << "\n"; },
        [](int a, int b) -> bool { return a > b;}
    );
    bst.insert(8);
    bst.insert(5);
    bst.insert(14);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(11);
    bst.insert(13);
    bst.insert(16);
    bst.insert(20);
    int a = 3;
    int b = 7;
    std::cout << "Lowest common ancestor of " << a << " and " << b << " is " << bst.lowestCommonAncestor(a,b);
    return 0;
}