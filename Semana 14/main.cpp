#include "UndirectedGraph.hpp"

enum TipoOperacion {
    RETIRO,
    DEPOSITO,
    CONSULTA,
    NULA
};

class Operacion {
public:
    int dni;
    int numeroTarjeta;
    float monto;
    int mes;
    int anio;
    TipoOperacion tipoOperacion;

    static Operacion crearOperacionPorDefecto() {
        return {777, 888, 0.00, 11, 2023, TipoOperacion::NULA };
    }
};


int main() {
    GrafoNoDirigido<Operacion> grafo = GrafoNoDirigido<Operacion>();
    for(int i = 0; i < 5; ++i) grafo.agregarVertice(i, Operacion::crearOperacionPorDefecto());


    grafo.agregarArista(0, 1, 20);
    grafo.agregarArista(0, 2, 30);
    grafo.agregarArista(1, 3, 40);
    grafo.agregarArista(2, 3, 50);
    grafo.agregarArista(2, 4, 10);
    grafo.agregarArista(3, 4, 10);

    grafo.print();

    grafo.dfs();
    return 0;
}