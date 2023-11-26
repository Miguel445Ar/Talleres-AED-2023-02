#include <iostream>
#include "Registro.hpp"

int main() {
    Registro registro;
    registro.listarDatos();
    registro.ordenarDatos();
    registro.listarDatos();
    registro.crearListaDeDnis();
    registro.pasarAHashTable();
    registro.generarArbol();
    registro.generarGrafo();
    return 0;
}