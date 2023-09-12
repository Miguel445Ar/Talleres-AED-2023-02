// #include <iostream>
// #include <fstream>
// #include <string>

// /*
//     1     2     3
//     tipo de fruta de cada cesta
//     naranjas mixto manzanas
// */


// int main() {
//     std::ifstream arch("input.txt"); // 1
//     std::string content; // 1
//     arch >> content; // 1
//     if(content == "M") { // 1
//         std::cout << "N Mixto M"; // 1
//     }else {
//         std::cout << "Mixto M N"; // 1
//     }
    
//     return 0;
// }

#include <iostream>
#include <vector>
#include <functional>

template<class T>
class Matrix2d {
public:
    Matrix2d(int n, int m, T defaultValue,
        std::function<bool(T)> isDefaultValue):
         _matrixRows(n), _matrixColumns(m), _isDefaultValue(isDefaultValue),
         _defaultValue(defaultValue) {
        _capacity = n * m;
        _elements = new T[_capacity];
        for(size_t i = 0; i < _capacity; ++i)
            _elements[i] = defaultValue;
    }
    ~Matrix2d() {
        delete[] _elements;
    }
    void insert(int row, int column, T newValue) {
        // Formula = cantidad filas * fila + columna => posicion arreglo
        if(row < 0 || column < 0) { // 3
            throw new std::runtime_error("Índice de fila o columna inválido");
        }
        size_t pos = (_matrixRows * row) + column; // 3
        if(pos >= _capacity) // 1
            throw new std::out_of_range("Position is out of range");
        _elements[pos] = newValue;  // 2
        // Notacion Detallada = 9 = O(1)
    }
    void print() {
        for(size_t i = 0; i < _matrixRows; ++i) { // 1 + n (1 + ... + 2)
            for(size_t j = 0; j < _matrixColumns; ++j) { // 1 + m (1+ )
                size_t pos = _matrixRows * i + j;
                if(_isDefaultValue(_elements[pos])) {
                    std::cout << "Empty ";
                    continue; 
                }
                std::cout << _elements[pos] << " ";
            }
            std::cout << "\n";
        }
    }
    void erase(int row, int column) {
        if(row < 0 || column < 0) { // 3
            throw new std::runtime_error("Índice de fila o columna inválido");
        }
        size_t pos = _matrixRows * row + column; // 3
        if(pos >= _capacity) // 1
            throw new std::out_of_range("Position is out of range");
        _elements[pos] = _defaultValue;
    }
private:
    T* _elements;
    T _defaultValue;
    size_t _capacity;
    size_t _matrixRows;
    size_t _matrixColumns;
    std::function<bool(T)> _isDefaultValue;
};

int main() {
    Matrix2d<int> matrix2d(5,4, -1, [](int value) -> bool { return value == -1; });
    matrix2d.print();
    matrix2d.insert(2,3, 20);
    std::cout << "\n----------------------------------\n";
    matrix2d.print();
    return 0;
}