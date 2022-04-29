#include "Punto.h"

Punto::Punto(int f, int c) : 
    fila(f), columna(c) {

    arriba = NULL;
    abajo = NULL;
    izquierda = NULL;
    derecha = NULL;

    jugador1Posicionado = false;
    jugador2Posicionado = false;

}

Punto::Punto(const Punto& p) {

    this->fila = p.fila;
    this->columna = p.columna;
    this->jugador1Posicionado = p.jugador1Posicionado;
    this->jugador2Posicionado = p.jugador2Posicionado;

    this->abajo = NULL;
    this->arriba = NULL;
    this->izquierda = NULL;
    this->derecha = NULL;

    if (p.abajo != NULL)
        this->abajo = new Punto(p.abajo->fila, p.abajo->columna);

    if (p.arriba != NULL)
        this->arriba = new Punto(p.arriba->fila, p.arriba->columna);

    if (p.izquierda != NULL)
        this->izquierda = new Punto(p.izquierda->fila, p.izquierda->columna);

    if (p.derecha != NULL)
        this->derecha = new Punto(p.derecha->fila, p.derecha->columna);


}

Punto::~Punto() {}

Punto* Punto::getArriba() const { return arriba; }
void Punto::setArriba(Punto* arriba) { this->arriba = arriba; }

Punto* Punto::getAbajo() const { return abajo; }
void Punto::setAbajo(Punto* abajo) { this->abajo = abajo; }

Punto* Punto::getIzquierda() const { return izquierda; }
void Punto::setIzquierda(Punto* izquierda) { this->izquierda = izquierda; }

Punto* Punto::getDerecha() const { return derecha; }
void Punto::setDerecha(Punto* derecha) { this->derecha = derecha; }

bool Punto::getJugador1Posicionado() const { return jugador1Posicionado; }
void Punto::setJugador1Posicionado(bool jugador1Posicionado) { this->jugador1Posicionado = jugador1Posicionado; }

bool Punto::getJugador2Posicionado() const { return jugador2Posicionado; }
void Punto::setJugador2Posicionado(bool jugador2Posicionado) { this->jugador2Posicionado = jugador2Posicionado; }

int Punto::getFila() const { return fila; }

void Punto::setFila(int fila) { this->fila = fila; }

int Punto::getColumna() const { return columna; }
void Punto::setColumna(int columna) { this->columna = columna;  }

Punto& Punto::operator = (const Punto& p) {

    this->fila = p.fila;
    this->columna = p.columna;
    this->jugador1Posicionado = p.jugador1Posicionado;
    this->jugador2Posicionado = p.jugador2Posicionado;   

    this->abajo = NULL;
    this->arriba = NULL;
    this->izquierda = NULL;
    this->derecha = NULL;

    if (p.abajo != NULL)
        this->abajo = new Punto(p.abajo->fila, p.abajo->columna);

    if (p.arriba != NULL)
        this->arriba = new Punto(p.arriba->fila, p.arriba->columna);

    if (p.izquierda != NULL)
        this->izquierda = new Punto(p.izquierda->fila, p.izquierda->columna);

    if (p.derecha != NULL)
        this->derecha = new Punto(p.derecha->fila, p.derecha->columna);

    return *this;

}

void Punto::guardaPunto(ofstream& out) {

    out << fila << DELIMITA_REGISTRO;
    out << columna << DELIMITA_REGISTRO;

}

void Punto::leePunto(ifstream& in) {

    string _f;
    string _c;

    getline(in, _f);
    getline(in, _c);

    fila = atoi(_f.c_str());
    columna = atoi(_c.c_str());

}