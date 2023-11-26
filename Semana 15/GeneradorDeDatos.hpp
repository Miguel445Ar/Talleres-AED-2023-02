#ifndef __GENERADOR_DE_DATOS_HPP__
#define __GENERADOR_DE_DATOS_HPP__

#include "Operacion.hpp"
#include <stdlib.h>
#include <iostream>


#define RANDOM(a, b) a + rand() % (b - a + 1)

class GeneradorDeDatos {
public:

    static Operacion crearOperacionPorDefecto() {
        return {777, 888, 0.00, 11, 2023, TipoOperacion::NULA };
    }

    static Operacion ingresarOperacion() {
        int dniAleatorio;
        long long numeroTarjeta;
        int montoAleatorio;
        int mes, anio;
        TipoOperacion tipoOperacion;
        std::cout << "\nIngrese dni: "; std::cin >> dniAleatorio;
        std::cout << "\nNumero de tarjeta: "; std::cin >> numeroTarjeta;
        std::cout << "\nMonto: "; std::cin >> montoAleatorio;
    }
    static Operacion crearOperacionAleatoria() {
        int dniAleatorio = RANDOM(10000000, 99999999);
        long long numeroTarjeta = RANDOM(1000000000, 9999999999);
        int montoAleatorio = RANDOM(10000, 99999);
        int mes = RANDOM(1,12);
        int anio = RANDOM(2000, 2023);
        TipoOperacion tipoOperacion = (TipoOperacion)(RANDOM(0,2));
        return { dniAleatorio, numeroTarjeta, montoAleatorio, mes, anio, tipoOperacion };
    }
};
#endif