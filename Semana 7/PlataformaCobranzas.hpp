#ifndef __PLATAFORMA_COBRANZAS_HPP__
#define __PLATAFORMA_COBRANZAS_HPP__


#include "Cola.hpp"
#include "PersonaAdulta.hpp"


class PlataformaCobranzas {
public:
    PlataformaCobranzas() {
        _cola = new Queue<PersonaAdulta>(
            [](PersonaAdulta p) -> void {
                std::cout << p << "\n";
            }
        );
    }
    PersonaAdulta realizarCobro() {
        return _cola->pop();
    }
    void insertarNuevoCobro() {

    }
private:
    Queue<PersonaAdulta>* _cola;
};

#endif