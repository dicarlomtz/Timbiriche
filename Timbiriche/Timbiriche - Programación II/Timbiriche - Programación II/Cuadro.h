#pragma once
#include "Punto.h"

class Cuadro {

private:

	Punto* p1;
	Punto* p2;
	Punto* p3;
	Punto* p4;
	int jugador;

public:

	Cuadro(Punto* = NULL, Punto* = NULL, Punto* = NULL, Punto* = NULL, int = 0);
	virtual ~Cuadro();
	bool conformanCuadro(Punto*, Punto*, Punto*, Punto*);

    Punto* getP1() const;
    void setP1(Punto* p1);

    Punto* getP2() const;
    void setP2(Punto* p2);

    Punto* getP3() const;
    void setP3(Punto* p3);

    Punto* getP4() const;
    void setP4(Punto* p4);

    int getJugador() const;
    void setJugador(int jugador);

};