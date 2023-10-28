#include <iostream>
#include <fstream>
#include "BST.hpp"
#include "HashTable.hpp"
#include "SortingAlgorithms.hpp"
#include <cstring>
#include <sstream>
#include <vector>


using std::cout;
using std::cin;

class Register {
public:
    int id;
    std::string country;
    unsigned totalCases;
    unsigned totalDeaths;
    unsigned newDeaths;
    unsigned totalRecovered;
    unsigned activeCases;
    unsigned seriousCritical;
    unsigned totalCasesPerMillion;
    unsigned deathsPerMillion;
    unsigned testsPerMillion;
    unsigned population;
    friend std::ostream& operator<<(std::ostream& os, Register r) {
        os << "(" << r.id << ", " << r.country << ", " <<  r.deathsPerMillion << ")";
        return os;
    }
};

class RegisterManagement {
    std::vector<Register> data;
    HashTable<Register>* ht;
    BinarySearchTree<Register>* bst;
public:
    RegisterManagement() {
        ht = new HashTable<Register>(20);
        bst = new BinarySearchTree<Register>(
            [](Register a, Register b) -> bool {
            return a.deathsPerMillion < b.deathsPerMillion;
            },
            [](Register a, Register b) -> bool {
            return a.deathsPerMillion == b.deathsPerMillion;
            },
            [](Register a) -> void {
                cout << a << "\n";
            }
        );
        _readData();
    }
    void menu() {
        int opc;
        while(true) {
            do {
              cout << "1. Ordenar con Mergesort\n";
              cout << "2. \n";
              cout << "3. Salir\n";
              cout << "Ingresa una opcion: "; 
              cin >> opc;
              cout << "\n";
            }while(!(opc >= 1 && opc <= 3));
            if(opc == 3) break;
            switch (opc)
            {
            case 1:
                orderRegisters();
                break;
            }
        }
    }
    void test() {
        orderRegisters();
        transferDataToHT();
        transferDataToBST();
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
            int id;
            std::string country;
            std::getline(s,aux, ',');
            id = std::stoi(aux);
            std::getline(s,aux,',');
            country = aux;
            unsigned arr[10];
            for(int i = 0; i < 10; ++i) {
                std::getline(s,aux,',');
                arr[i] = std::stoi(aux);
            }
            Register r{id, country, arr[0], arr[1], arr[2], 
            arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]};
            data.push_back(r);
            std::cout << r << "\n";
        }
    }
    void orderRegisters() {
        int n = data.size();

        Register* arr = new Register[n];
        for(int i = 0; i < n; ++i) arr[i] = data[i];

        SortingAlgorithms<Register>::mergeSort(0,n - 1, arr, 
        [](Register a, Register b) -> bool {
            return a.deathsPerMillion < b.deathsPerMillion;
        });
        std::cout << "\nLos registros ordenados son: \n";
        for(int i = 0; i < n; ++i) std::cout << arr[i] << "\n";
        std::cout << "\n";
        delete[] arr;
    }
    void transferDataToHT() {
        for(Register& r: data) {
            ht->insert(r.country, r);
        }
        cout << "\n----------------------------------------\n";
        ht->display([](Register a) -> void {
            cout << a << "\n";
        });
        cout << "\n-------------------------------------\n";
    }
    void transferDataToBST() {
        for(Register& r: data) {
            bst->insert(r);
        }
        cout << "\n----------------------------------------\n";
        bst->preOrder();
        cout << "\n-------------------------------------\n";
        cout << "\nTotal registros en el arbol: " << bst->size() << "\n";
        cout << "\nAltura del arbol: " << bst->height() << "\n";
        cout << "\n----------Recorrido en orden----------------------\n";
        bst->inOrder();
        cout << "\n-------------------------------------\n";
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
    rm.test();
    return 0;
}