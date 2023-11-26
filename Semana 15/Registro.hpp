#ifndef __REGISTRO_HPP__
#define __REGISTRO_HPP__

#include <vector>
#include <iostream>
#include "Operacion.hpp"
#include "GeneradorDeDatos.hpp"
#include "SortingAlgorithms.hpp"
#include "HashTable.hpp"
#include "DLL.hpp"
#include "BST.hpp"
#include "UndirectedGraph.hpp"

class Registro {
public:
    Registro() {
        _generarDatos();
    }
    void listarDatos() {
        std::cout << "\n---------------------------------\n";
        for(Operacion& operacion: operaciones) std::cout << operacion << "\n";
    }
    void ordenarDatos() {
        SortingAlgorithms<Operacion>::mergeSort(operaciones,
        [](Operacion a, Operacion b) -> bool { 
            return a.monto < b.monto;
        });
        std::cout << "\n---------------------------------\n";
        std::cout << "\nOperaciones ordenadas exitosamente";
    }
    void pasarAHashTable() {
        HashTable<Operacion> ht(1000);
        for(Operacion& operacion: operaciones) {
            ht.insertar(std::to_string(operacion.numeroTarjeta), operacion);
        }
        std::cout << "\n---------------------------------\n";
        ht.mostrar([](Operacion operacion) -> void {
            std::cout << operacion << "\n";
        });
    }
    void crearListaDeDnis() {
        DoublyLinkedList<int>* dll = DoublyLinkedList<Operacion>::createFromVector<int>(operaciones,
            [](int v) -> void { std::cout << v << "-->"; }, 
            [](Operacion op) -> int {
                return op.dni;
            }
        );
        std::cout << "\n---------------------------------\n";
        dll->display();
    }
    void generarArbol() {
        BinarySearchTree<Operacion> bst(
            [](Operacion a, Operacion b) {
                return a.monto < b.monto;
            },
            [](Operacion a, Operacion b) {
                return a.monto == b.monto;
            },
            [](Operacion op) -> void {
                std::cout << op << "\n";
            },
            [](Operacion a, Operacion b) {
                return a.monto > b.monto;
            }
        );
        for(Operacion operacion: operaciones) {
            bst.insert(operacion);
        }
        std::cout << "\n---------------------------------\n";
        bst.postOrder();
        sumarHijosDerechosArbol(bst);
    }
    void generarGrafo() {
        GrafoNoDirigido<Operacion> g;
        // A: 0 - B: 1 - C: 2 - D: 3 - E: 4 - F: 5
        // A: 65, B: 66, ..
        g.agregarVertice('A', GeneradorDeDatos::crearOperacionPorDefecto());
        g.agregarVertice('B', GeneradorDeDatos::crearOperacionPorDefecto());
        g.agregarVertice('C', GeneradorDeDatos::crearOperacionPorDefecto());
        g.agregarVertice('D', GeneradorDeDatos::crearOperacionPorDefecto());
        g.agregarVertice('E', GeneradorDeDatos::crearOperacionPorDefecto());
        g.agregarVertice('F', GeneradorDeDatos::crearOperacionPorDefecto());
        
        g.agregarArista('A', 'B', 20);
        g.agregarArista('B', 'C', 40);
        g.agregarArista('C', 'D', 15);
        std::cout << "\n---------------------------------\n";
        g.print();
    }
private:
    void sumarHijosDerechosArbol(BinarySearchTree<Operacion>& bst) {
        int result = bst.sumAllRightChilds([](Operacion operacion) -> int {
            return operacion.monto;
        });
        std::cout << "\n---------------------------------\n";
        std::cout << "\nSuma de todos los hijos derechos: " << result;
    }

private:
    std::vector<Operacion> operaciones;
private:
    void _generarDatos() {
        int cantidad = 500;
        while(cantidad--) {
            operaciones.push_back(GeneradorDeDatos::crearOperacionAleatoria());
        }
    }
};

#endif