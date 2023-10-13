#ifndef __PERSONA_ADULTA_HPP__
#define __PERSONA_ADULTA_HPP__

#include <iostream>
#include <string>

#define RANDOM(a,b) a + rand() % (b - a + 1)

using std::string;
using std::ostream;

enum SexoPersona {
    HOMBRE,
    MUJER
};

class PersonaAdulta {
public:
    PersonaAdulta(string dni, unsigned edad, SexoPersona sexo, 
    unsigned monto, string celular, int pos):
    _dni(dni), _edad(edad), _sexo(sexo), _monto(monto), _celular(celular), _pos(pos){}
    void setMonto(int monto) {
        this->_monto = monto;
    }
    unsigned getMonto() {
        return this->_monto;
    }
    unsigned getEdad() {
        return this->_edad;
    }
    int getPos() {
        return _pos;
    }
    void decrementarPos() {
        --this->_pos;
    }
    void incrementarPos() {
        ++this->_pos;
    }
    friend std::ostream& operator<<(std::ostream& os, PersonaAdulta p) {
        os << "(dni=" << p._dni << ", edad=" << p._edad << ", sexo=" << (p._sexo == SexoPersona::HOMBRE?"Hombre":"Mujer") << ", monto=" << p._monto << ")";
        return os;
    }
    static PersonaAdulta generarPersonaAdulta(int pos) {
        string dni = std::to_string(RANDOM(10000000,99999999));
        unsigned edad = (unsigned) RANDOM(18,80);
        int r = RANDOM(1, 2);
        SexoPersona sexo;
        if(r == 1) sexo = SexoPersona::HOMBRE;
        else sexo = SexoPersona::MUJER;
        unsigned monto = 0;
        string celular = std::to_string(RANDOM(900000000,999999999));
        return PersonaAdulta(dni,edad,sexo,monto,celular, pos);
    }
private:
    string _dni;
    unsigned _edad;
    SexoPersona _sexo;
    unsigned _monto;
    string _celular;
    int _pos;
};


#endif