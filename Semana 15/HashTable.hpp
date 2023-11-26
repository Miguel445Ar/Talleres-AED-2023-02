#ifndef __HASH_TABLE_HPP__
#define __HASH_TABLE_HPP__
#include <iostream>
#include <functional>
#include <string>

using std::string;

template<class T>
class HashTable {
    class HashEntidad {
    private:
    	std::string key;
    	T value;
    public:
    	HashEntidad(std::string key, T value) {
    		this->key = key;
    		this->value = value;
    	}
    	std::string getKey() { return key; }
    	T getValue() { return value; }
    };
private:
	HashEntidad** tabla;
	int numElementos;
	int TABLE_SIZE;

public:
	HashTable(int TABLE_SIZE = 128) {
		this->TABLE_SIZE = TABLE_SIZE;
		tabla = new HashEntidad * [TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; ++i) {
			tabla[i] = nullptr;
		}
		numElementos = 0;
	}
	~HashTable()
	{
		for (int i = 0; i < TABLE_SIZE; ++i) {
			if (tabla[i] != nullptr) {
				delete tabla[i];
			}
		}
		delete[] tabla;
	}
    void mostrar(std::function<void(T)> show) {
        for(int i = 0; i < TABLE_SIZE; ++i) {
            if(tabla[i] == nullptr) continue;
            std::cout << "Indice: " << i;
            show(tabla[i]->getValue());
        }
    }
	int generateKey(string s) {
		int key = 0;
		for (int i = 0; i < s.size(); i++)
		{
			key += int(char(s[i]));
		}
		return key;
	}
	//Direccionamiento según Prueba Lineal
	void insertar(string key, T value) {
		//Hash prima
		int base, step, hash;
		//validar si la tabla está llena
		if (numElementos == TABLE_SIZE)return;
		//Función Hash1
		base = generateKey(key) % TABLE_SIZE;
		hash = base;
		//constante para Hash2
		step = 0;
		while (tabla[hash] != nullptr)
		{
			//Función Hash2
			hash = (base + step) % TABLE_SIZE;
			step++;
		}
		//almacenarlo en la tabla
		tabla[hash] = new HashEntidad(key, value);
		numElementos++;
	}
	int size() {
		return TABLE_SIZE;
	}
	int sizeactual() {
		return numElementos;
	}

	//retorna el indice de la tabla
	// int buscarS(string key) {
	// 	int step = 0;
	// 	int i, base;
	// 	int iteraciones = 0;
	// 	i = base = generateKey(key) % TABLE_SIZE;
	// 	while (true)
	// 	{
	// 		if (iteraciones >= TABLE_SIZE) return -1;
	// 		if (tabla[i] == nullptr) return -1;
	// 		else if (tabla[i]->getKey() == key && tabla[i]->getValue()->getNombre() == key) {
	// 			return i;
	// 		}
	// 		else step++; iteraciones++;

	// 		i = (base + step) % TABLE_SIZE;
	// 	}
	// }

	//devuelve un valor de verdadero si se encontro la obra y la almacena en una obra puntero
	// bool obtenerS(string key, T& obr) {
	// 	int indice = buscarS(key);
	// 	if (indice != -1) {
	// 		obr = tabla[indice]->getValue();
	// 		return true;
	// 	}
	// 	return false;
	// }

	// bool seEncuentra(string key) {
	// 	int indice = buscarS(key);
    //  return indice != 1;
	// 	if (indice != -1) {
	// 		return true;
	// 	}
	// 	else {
	// 		return false;
	// 	}
	// }
};

#endif