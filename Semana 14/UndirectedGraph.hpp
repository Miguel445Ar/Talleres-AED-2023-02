#ifndef __UNDIRECTED_GRAPH__
#define __UNDIRECTED_GRAPH__
#include <list>
#include <vector>
#include <iostream>

template<class T = int>
class GrafoNoDirigido {
    class Arista {
    public:
        int peso;
        int indiceVerticeAdyacente;
    };
public:
    class Vertice {
    public:
        int index;
        T value;
        std::list<Arista*> listaDeAdyacencia;
    };
public:
    GrafoNoDirigido() {

    }
    void agregarVertice(int indiceVertice, T valorVertice) {
        if(existeVertice(indiceVertice)) return;
        aumentarTamanioDelGrafo(indiceVertice + 1);
        agregarNuevoVertice(indiceVertice, valorVertice);
    }
    void agregarArista(int indiceVerticeA, int indiceVerticeB, int peso) {
        if(existeVertice(indiceVerticeA) == false || existeVertice(indiceVerticeB) == false) return;
        // Agregamos la relación de A hacia B
        Vertice* verticeA = grafo[indiceVerticeA];
        if(verticeExisteEnListaDeAdyacenia(verticeA, indiceVerticeB) == false) {
            verticeA->listaDeAdyacencia.push_back(new Arista {peso, indiceVerticeB});
        }
        // Agregamos la relación de B hacia A
        Vertice* verticeB = grafo[indiceVerticeB];
        if(verticeExisteEnListaDeAdyacenia(verticeB, indiceVerticeA) == false) {
            verticeB->listaDeAdyacencia.push_back(new Arista {peso, indiceVerticeA});
        } 
    }
    void dfs() {
        std::vector<bool> verticesVisitados(grafo.size(), false);
        std::vector<int> antecesores(grafo.size(), -1);
        Vertice* v = grafo[0];
        _dfs(v,-1, verticesVisitados, antecesores);
        for(int i = 0; i < antecesores.size(); ++i) { 
            std::cout << i << ": " << antecesores[i] << "\n";
        }

    }
    void _dfs(Vertice* vertice, int indiceVerticeAntecesor, std::vector<bool>& visitados, std::vector<int>& antecesores) {
        if(visitados[vertice->index]) return;
        visitados[vertice->index] = true;
        antecesores[vertice->index] = indiceVerticeAntecesor;
        for(Arista* arista: vertice->listaDeAdyacencia) {
            _dfs(grafo[arista->indiceVerticeAdyacente], vertice->index, visitados, antecesores);
        }
    }

    void print() {
        for(Vertice* v: grafo) {
            if(v == nullptr) continue;
            std::cout << v->index << ": [ ";
            for(Arista* arista: v->listaDeAdyacencia) {
                std::cout << "( v: " << arista->indiceVerticeAdyacente << ", p: " << arista->peso << "), ";
            }
            std::cout << "]\n";
        }
    }

private:
    std::vector<Vertice*> grafo;
private:
    // Para saber si vertice u, está en la lista de adyacencoa de v
    bool verticeExisteEnListaDeAdyacenia(Vertice* vertice, int indiceVerticeQueBusco) {
        for(Arista* arista: vertice->listaDeAdyacencia) if(arista->indiceVerticeAdyacente == indiceVerticeQueBusco) return true;
        return false;
    }
    bool existeVertice(int indiceVertice) {
        return indiceVertice < grafo.size() && indiceVertice >= 0 && grafo[indiceVertice] != nullptr;
    }
    void aumentarTamanioDelGrafo(int indiceVertice) {
        grafo.resize(indiceVertice + 1, nullptr);
    }
    void agregarNuevoVertice(int indiceNuevoVertice, T valorNuevoVertice) {
        grafo[indiceNuevoVertice] = new Vertice {indiceNuevoVertice, valorNuevoVertice};
    }
};

#endif