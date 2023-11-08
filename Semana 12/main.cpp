#include <iostream>
#include "BST.hpp"

int main() {
    BinarySearchTree<int> bst(
        [](int a, int b) -> bool {
            return a < b;
        },
        [](int a, int b) -> bool {
            return a + b;
        },
        [](int value) -> void {
            std::cout << value << "\n";
        },
        [](int a, int b) -> bool {
            return a > b;
        }
    );
    bst.insert(1);
    bst.insert(2);
    bst.insert(3);
    bst.insert(4);
    bst.insert(5);
    bst.insert(6);
    bst.insert(7);
    bst.insert(8);
    // std::cout << "Height: " << bst.height();
    // bst.preOrder();
    // bst.inOrder();
    // bst.postOrder();
}