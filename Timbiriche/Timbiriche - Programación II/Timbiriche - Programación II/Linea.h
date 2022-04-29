#pragma once
#include "Punto.h"

class Linea {

private:

	Punto* p1;
	Punto* p2;
	int jugador;
	string direP1;

public:

	Linea(Punto* = NULL, Punto* = NULL, int = 0, string = "");
	Linea(const Linea&);
	virtual ~Linea();
	bool conformanLinea(Punto*, Punto*);

    Punto* getP1() const;
    void setP1(Punto* p1);

    Punto* getP2() const;
    void setP2(Punto* p2);

    int getJugador() const;
    void setJugador(int jugador);

	string getDireP1() const;
	void setDireP1(string direP1);

	Linea& operator = (const Linea&);

	void guardaLinea(ofstream&);
	void leeLinea(ifstream&);

};