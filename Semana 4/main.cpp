#include <iostream>
#include <list>
#include "LinkedList.hpp"

using std::cout;

int main() {
    LinkedList<int> list;
    list.pushBack(3);
    list.pushBack(8);
    list.pushBack(9);
    list.pushBack(10);
    list.print([](int value) -> void {
        std::cout << value << "-->";
    });
    list.reverse();
    std::cout << "\n---------------------------------------\n";
    list.print([](int value) -> void {
        std::cout << value << "-->";
    });
    list.pushBack(20);
    std::cout << "\n---------------------------------------\n";
    list.print([](int value) -> void {
        std::cout << value << "-->";
    });
    return 0;
}