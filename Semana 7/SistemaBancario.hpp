#ifndef __SIST_HPP__
#define __SIST_HPP__

#include "AgenciaBancaria.hpp"
#include "BaseDeDatos.hpp"
#include "PlataformaCobranzas.hpp"

class SistemaBancario {
public:
    SistemaBancario() {

    }
    void insertarPersonaAdulta() {
        // pedirle al usuario los datos para insertar una nueva persona
    }
    void realizarCobro() {
        PersonaAdulta p1 = plataformaCobranzas.realizarCobro();
        bd.eliminarPersonaAdulta(p1.getPos());
        ab.efectuarCobro(p1);
        bd.reInsertarPersonaAdulta(p1, p1.getPos());
    }
private:
    BaseDeDatos bd;
    AgenciaBancaria ab;
    PlataformaCobranzas plataformaCobranzas;
};

#endif