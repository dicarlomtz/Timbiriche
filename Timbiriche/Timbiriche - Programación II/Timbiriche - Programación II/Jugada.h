#pragma once
#include "MatrizCampo.h"
#include "NumeroAleatorio.h"

class Jugada {

private:

	bool cuadroCapturado; // si se captura un cuadro se settea como true, caso contrario false.

protected:

	MatrizCampo* m; //Recibe un campo de juego, las jugadas se cambian con casteo dinamico.

public:

	Jugada(MatrizCampo*);
	virtual ~Jugada();

	//Verifica si se puede seguir jugando
	bool masJugadas();
	//-------------------------------------------------------------------------------

	//Realiza la jugada
	virtual bool realizarJugada(int) = 0; //recibe jugador 1 o 2
	//-------------------------------------------------------------------------------

	void setCuadroCapturado(bool);
	bool getCuadroCapturado() const;

protected:

	//Verifica si se pueden enlazar los puntos
	virtual bool verificaArriba(int, int, int) = 0;
	virtual bool verificaAbajo(int, int, int) = 0;
	virtual bool verificaIzquierda(int, int, int) = 0;
	virtual bool verificaDerecha(int, int, int) = 0;
	//---------------------------------------

	//Enlaza los puntos
	virtual bool enlazaArriba(int, int, int) = 0;
	virtual bool enlazaAbajo(int, int, int) = 0;
	virtual bool enlazaIzquierda(int, int, int) = 0;
	virtual bool enlazaDerecha(int, int, int) = 0;
	//----------------------------------------

	//Coloca los jugadores en los puntos
	void posicionarJugador(int, int, int, int, int);
	//----------------------------------------
	
	//Determina si hacer una jugada es riesgosa
	bool riesgoArriba(int, int);
	bool riesgoAbajo(int, int);
	bool riesgoIzquierda(int, int);
	bool riesgoDerecha(int, int);
	//----------------------------------------

	//Coloca los puntos que forman un cuadro
	void cuadroArriba(int, int, int);
	void cuadroAbajo(int, int, int);
	void cuadroIzquierda(int, int, int);
	void cuadroDerecha(int, int, int);
	//----------------------------------------

};