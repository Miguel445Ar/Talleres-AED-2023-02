#include <iostream>
#include "SortingAlgorithms.hpp"
#include <string>
#include <unordered_map>

struct Persona {
    std::string dni;
    int edad;
    std::string nombre;
    std::string apellido;
    friend std::ostream& operator<<(std::ostream& os, Persona p) {
        os << "(" << p.dni << ", " << p.edad << ")";
        return os;
    }
};

int main() {
    int arr[] = {9,1,2,4,5,6,10,3};
    SortingAlgorithms<int>::quicksort(0,7,arr,
    [](int a, int b) -> bool { return a < b;});
    for(int i = 0; i < 8; ++i) std::cout << arr[i] << " ";

    std::cout << "\n----------------------------------\n";

    Persona personas[] = {
        {"458595", 20, "Miguel", "Cahuas"},
        {"854985", 20, "Gabriel", "Casas"},
        {"894485", 30, "Nombre", "Apellido"},
        {"894485", 14, "Nombre", "Apellido"},
        {"894485", 18, "Nombre", "Apellido"},
        {"894485", 32, "Nombre", "Apellido"}
    };
    SortingAlgorithms<Persona>::quicksort(0,5,personas,
    [](Persona a, Persona b) -> bool {
        return a.edad < b.edad;
    });

    for(int i = 0; i < 6; ++i) std::cout << personas[i] << "\n";

    
    std::cout << "\n----------------------------------\n";


    std::string text = "jfkfjjjjjfotointt";

    std::unordered_map<char,int> umap;
    for(char c:  text) {
        if(umap.count(c) == 0) {
            umap[c] = 1;
            continue;
        }
        umap[c] += 1;
    }
    for(auto p: umap) {
        std::cout << "[" << p.first << " -> " << p.second << "]\n";
    } 


    return 0;
}