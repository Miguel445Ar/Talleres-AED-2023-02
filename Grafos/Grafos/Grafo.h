#pragma once

#include <vector>
using namespace std;

template<class T, T vacio = -1>
class CGrafo {
private:
	//Crearndo class CArco con el T info e índice vacio, representa la unión de los indices
	class CArco {
	public:
		T info;
		int v; //indice del vertice de llegada
		CArco(int vLlegada) {
			info = vacio;
			v = vLlegada; //vértice a donde llegará
		}
	};
	class CVertice {
	public:
		T info; // contiene su información
		vector<CArco*>* ady; //Lista de adyacencia de class CArco, puntero vector
		CVertice() {
			info = vacio;
			ady = new vector<CArco*>();
		}
	};
	//Lista de vértices
	vector<CVertice*>* vertices;

public:
	CGrafo() { //constructor del grafo
		vertices = new vector<CVertice*>();
	}

	//Operaciones del Grafo
	int adicionarVertice(T info) {
		CVertice* vert = new CVertice(); //puntero temporal
		vert->info = info; //asigna la informacion (clase del grafo) al vertice temporal
		vertices->push_back(vert); //agrega el vertice, al ser puntero usa ->
		return vertices->size() - 1;
	}

	int cantidadVertices() {
		return vertices->size();//retorna la cantidad de verticas
	}

	T obtenerVertice(int v) {
		return (vertices->at(v))->info;//retorna uno de los vertices según la posicion ingresada
	}
	void modificarVertice(int v, T info) {
		(vertices->at(v))->info = info;//permite modificar el valor info meidante un el indice del vertice
	}
	//Operaciones del CArco
	void adicionarArco(int v, int vLlegada) {//parametros indice del vertice, indice del verttice de llegada
		CVertice* ver = vertices->at(v);
		//Crear el objeto ARCO
		CArco* arc = new CArco(vLlegada); //crear arco temporal con el indice de vector de llegada
		ver->ady->push_back(arc);
	}

	int cantidadArcos(int v) {
		return (vertices->at(v)->ady->size()); //cantidad de arcos en un vertice de acuerdo al indice del vertice
	}

	T obtenerArco(int v, int apos) { //indice del vertice, indice del arco
		CVertice* ver = vertices->at(v); //vertice auxiliar para manejar el vertice
		return (ver->ady->at(apos))->info;//obtiene el valor del arco según la posicion brindada en el parametro
	}

	void modificarArco(int v, int apos, T info) {
		CVertice* ver = vertices->at(v);
		(ver->ady->at(apos))->info = info; //modifica el valor del arco
	}

	int obtenerVerticeLlegada(int v, int apos) {
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->v; //indice del vertice de llegada
	}
};