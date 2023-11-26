#ifndef __OPERACION_HPP__
#define __OPERACION_HPP__

#include <iostream>

enum TipoOperacion {
    RETIRO,
    TRANSFERENCIA,
    CAMBIO_DE_CLAVE,
    NULA
};

class Operacion {
public:
    int dni;
    long long numeroTarjeta;
    float monto;
    int mes;
    int anio;
    TipoOperacion tipoOperacion;
    friend std::ostream& operator<<(std::ostream& os, Operacion operacion) {
        os << "(" << operacion.dni << ", " << operacion.numeroTarjeta << ", " << operacion.monto << ")";
        return os;
    }
};

#endif