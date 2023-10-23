#include <iostream>
#include <fstream>
#include "BST.hpp"
#include "HashTable.hpp"
#include <cstring>
#include <sstream>


class Register {
public:
    int id;
    std::string country;
    friend std::ostream& operator<<(std::ostream& os, Register r) {
        os << "(" << r.id << ", " << r.country << ")";
        return os;
    }
};

class RegisterManagement {
    
public:
    RegisterManagement() {
        _readData();
    }
private:
    void _readData() {
        std::ifstream archivoLectura("Covid.csv");
        if(archivoLectura.is_open() == false)
            throw "File does not exist";
        std::string line;
        while(getline(archivoLectura, line, '\n')) {
            std::cout << line << "\n";
            std::stringstream s(line);
            std::string aux;
            Register r;
            std::getline(s,aux, ',');
            r.id = std::stoi(aux);
            std::getline(s,aux,',');
            r.country = aux;
            std::cout << r << "\n";
        }
    }
};


int main() {
    // BinarySearchTree<int> bst(
    //     [](int a, int b) -> bool { return a < b; },
    //     [](int a, int b) -> bool { return a == b; },
    //     [](int a) -> void { std::cout << a << "\n"; }
    // );
    // bst.insert(5);
    // bst.insert(3);
    // bst.insert(8);
    // bst.insert(2);
    // bst.insert(4);
    // bst.insert(10);
    // std::cout << "----------------------------------------------\n";
    // bst.inOrder();
    // std::cout << "----------------------------------------------\n";
    // bst.preOrder();
    // std::cout << "----------------------------------------------\n";
    // bst.postOrder();
    RegisterManagement rm;
    return 0;
}