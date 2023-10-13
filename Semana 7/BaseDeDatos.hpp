#ifndef __BASE_DE_DATOS_HPP__
#define __BASE_DE_DATOS_HPP__

#include "Cola.hpp"
#include "PersonaAdulta.hpp"

class BaseDeDatos {
public:
    BaseDeDatos() {
        _cola = new Queue<PersonaAdulta>(
            [](PersonaAdulta p) -> void {
                std::cout << p << "\n";
            }
        );
        pos = 0;
        int cantidad = 1000;
        while(cantidad--) insertarNuevaPersonaAdulta();
    }
    ~BaseDeDatos() {
        delete _cola;
    }
    int getPos() {
        return this->pos;
    }
    void insertarNuevaPersonaAdulta(int pos = -1) {
        if(pos == -1 || pos >= _cola->Size()) {
            _cola->push(PersonaAdulta::generarPersonaAdulta(this->pos));
            ++this->pos;
            return;
        }
    }
    void reInsertarPersonaAdulta(PersonaAdulta p, int pos) {
        _cola->insertAtPosition(p, pos);
    }
    PersonaAdulta eliminarPersonaAdulta(int pos) {
        return _cola->eraseAtPosition(pos);
    }
private:
    Queue<PersonaAdulta>* _cola;
    int pos;
};


#endif