#pragma once
#include "Empresa.h"

class Interfaz {

public:

    static void bienvenida();
    static int menu();
    static void despedida();

    //---------------------//

    static void registrarJugador(Empresa*);
    static void verCodigoObtenido(Empresa*);
    static void verPartida(Empresa*);

    //--------------------//

    static void cambiarDia(Empresa*);

    //------------------//

    static bool ingresarCodigo(Empresa*);
    static int elegirModoJuego();
    static MatrizCampo* obtenerCampoJuego();
    static Jugador* obtenerJugador1(Empresa*);
    static Jugador* obtenerJugador2();

};