#pragma once
#include "Jugada.h"

class CapturaPrimero : public Jugada {

public:

	CapturaPrimero(MatrizCampo*);
	virtual ~CapturaPrimero();
	bool realizarJugada(int); //Recibe jugador 1 o 2

protected:

	//Verifica si se pueden enlazar los puntos
	bool verificaArriba(int, int, int);
	bool verificaAbajo(int, int, int);
	bool verificaIzquierda(int, int, int);
	bool verificaDerecha(int, int, int);
	//---------------------------------------

	//Enlaza los puntos
	bool enlazaArriba(int, int, int);
	bool enlazaAbajo(int, int, int);
	bool enlazaIzquierda(int, int, int);
	bool enlazaDerecha(int, int, int);
	//----------------------------------------

};