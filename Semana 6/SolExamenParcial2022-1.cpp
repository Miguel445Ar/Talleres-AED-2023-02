#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include "DLL.hpp"


#define RANDOM(a,b) a + rand() % (a - b + 1)


class Recluta {
public:
    std::string nombre;
    std::string codigoRecluta;
    int barracasBaldeadasYBarridas;
    int baniosLimpiados;
    int murallasPintadas;
private:
    static std::string generarNombreAletorio(int length) {
        // A -> 65 - Z -> 90
        std::string s;
        for(unsigned int i = 0; i < length; ++i) {
            int asciiValue = RANDOM(65, 90);
            char character = static_cast<char>(asciiValue);
            s.push_back(character);
        }
        return s;
    }
public:
    static Recluta generarReclutaAletorio() {
        std::string nombre = generarNombreAletorio(8);
        std::string codigoRecluta = std::to_string(RANDOM(10000, 99999));
        return {nombre, codigoRecluta, 0,0,0};
    }
};

class Solution {
public:
    Solution() {
        reclutas = new DoublyLinkedList<Recluta>([](Recluta r) -> void {
            std::cout << "\n(Nombre recluta: " << r.nombre << "| Codigo Recluta: " << r.codigoRecluta << ")\n";
        });
        int cantidadBaseReclutas = 1420;
        while(cantidadBaseReclutas--) reclutas->pushBack(Recluta::generarReclutaAletorio());
        
    }
    ~Solution() {
        delete reclutas;
    }
    void modificarRecluta(Recluta& recluta) {
        
    }
    void empezar() {
        int currentPos = 0;
        while(reclutas->isEmpty() == false) {
            int pasos = RANDOM(1200, 12000);
            int pos;
            if(currentPos > 0) {
                pasos += (currentPos + 1);
            }
            pos = pasos % reclutas->size();
            currentPos = pos;
            bool eliminarRecluta = false;
            reclutas->modifyAt(pos, [this, &eliminarRecluta](Recluta& recluta) -> void {
                modificarRecluta(recluta);
                if(recluta.baniosLimpiados == 500) eliminarRecluta = true;
            });
            if(eliminarRecluta)
                reclutas->eraseAt(pos);
            agregarNuevosReclutas();
        }
    }

private:
    DoublyLinkedList<Recluta>* reclutas;
    void agregarNuevosReclutas() {
        int cantidadNuevosReclutas = RANDOM(1000, 7500);
        while(cantidadNuevosReclutas--) {
            int pos = RANDOM(0, reclutas->size() - 1);
            reclutas->insertAt(Recluta::generarReclutaAletorio(), pos);
        }
    }
};

int main() {

    return 0;
}