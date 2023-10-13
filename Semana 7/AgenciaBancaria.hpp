#ifndef __AGENCIA_BANCARIA_HPP__
#define __AGENCIA_BANCARIA_HPP__

#include "PersonaAdulta.hpp"

class AgenciaBancaria {
public:
    void efectuarCobro(PersonaAdulta& persona) {
        unsigned monto = RANDOM(500,800);
        persona.setMonto(monto);
    }
};

#endif