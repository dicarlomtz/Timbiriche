#pragma once
#include "Interfaz.h"
#include "Aleatorio.h"
#include "Central.h"
#include "Cercano.h"
#include "Islas.h"
#include "Periferico.h"
#include <Windows.h>

class InterfazPartida {

private:

    static MatrizCampo* m;
    static Jugador* v[2];

public:

    static void juega(Empresa* m);

private:

    static bool prepararPartida(Empresa*);
    static int tomarDesicion();
    static Jugada* escogerEstrategia();
    static Partida* guardarPartida();
    static void inicializarEstrategia();


};