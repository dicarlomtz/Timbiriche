#pragma once
#include "MatrizCampo.h"

class ColocaLineasCuadros {

public:

	//Enlaza los puntos
	bool enlazaArriba(int, int, int, MatrizCampo*);
	bool enlazaAbajo(int, int, int, MatrizCampo*);
	bool enlazaIzquierda(int, int, int, MatrizCampo*);
	bool enlazaDerecha(int, int, int, MatrizCampo*);
	//----------------------------------------

private:

	//Coloca los puntos que forman un cuadro
	void cuadroArriba(int, int, int, MatrizCampo*);
	void cuadroAbajo(int, int, int, MatrizCampo*);
	void cuadroIzquierda(int, int, int, MatrizCampo*);
	void cuadroDerecha(int, int, int, MatrizCampo*);
	//----------------------------------------

	//Coloca los jugadores en los puntos
	void posicionarJugador(int, int, int, int, int, MatrizCampo*);
	//----------------------------------------

};