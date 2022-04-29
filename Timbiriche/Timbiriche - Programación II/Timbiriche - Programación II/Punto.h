#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

#define DELIMITA_CAMPO '\t'
#define DELIMITA_REGISTRO '\n'

class Punto {

private:

	Punto* arriba;
	Punto* abajo;
	Punto* izquierda;
	Punto* derecha;

	bool jugador1Posicionado;
	bool jugador2Posicionado;

    int fila;
    int columna;

public:

    Punto(int f = 0, int c = 0);
    Punto(const Punto&);
    virtual ~Punto();

    Punto* getArriba() const;
    void setArriba(Punto* arriba);

    Punto* getAbajo() const;
    void setAbajo(Punto* abajo);

    Punto* getIzquierda() const;
    void setIzquierda(Punto* izquierda);

    Punto* getDerecha() const;
    void setDerecha(Punto* derecha);

    bool getJugador1Posicionado() const;
    void setJugador1Posicionado(bool jugador1Posicionado);

    bool getJugador2Posicionado() const;
    void setJugador2Posicionado(bool jugador2Posicionado);

    int getFila() const;
    void setFila(int);

    int getColumna() const;
    void setColumna(int);

    Punto& operator = (const Punto&);

    void guardaPunto(ofstream&);
    void leePunto(ifstream&);

};