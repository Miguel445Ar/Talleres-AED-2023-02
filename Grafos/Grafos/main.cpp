#include <iostream>
#include "Grafo.h"

using namespace std;

int main() {
	//Crear el grafo
	CGrafo<int>* G = new CGrafo<int>();

	//Agregar Vértices
	G->adicionarVertice(2); //indice=0
	G->adicionarVertice(15); //indice=1
	G->adicionarVertice(30); //indice=2
	G->adicionarVertice(7); //indice=3

	//Agregar los arcos
	G->adicionarArco(0, 1); //indice=0
	G->modificarArco(0, 0, 10);
	G->adicionarArco(0, 3);//indice=1
	G->modificarArco(0, 1, 20);
	G->adicionarArco(1, 2);//indice=0
	G->modificarArco(1, 0, 30);
	G->adicionarArco(2, 0);//indice=0
	G->modificarArco(2, 0, 40);

	//Imprimir los vértices con sus arcos
	for (int i = 0; i < G->cantidadVertices(); ++i) {
		cout << "Vertice : " << G->obtenerVertice(i) << endl;
		for (int j = 0; j < G->cantidadArcos(i); j++)
		{
			cout << "Arco->" << G->obtenerArco(i, j) << " ";
		}
		cout << endl;
	}

	cin.get();
	cin.ignore();
	return 0;
}