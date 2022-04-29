#include "Cuadro.h"

Cuadro::Cuadro(Punto* p1, Punto* p2, Punto* p3, Punto* p4, int ju) : 
    p1(p1), p2(p2), p3(p3), p4(p4), jugador(ju) {}

Cuadro::~Cuadro() {}

bool Cuadro::conformanCuadro(Punto* p1_ptr, Punto* p2_ptr, Punto* p3_ptr, Punto* p4_ptr) {

    int cont = 0;

    if (p1 == p1_ptr || p1 == p2_ptr || p1 == p3_ptr || p1 == p4_ptr)
        cont++;
    if (p2 == p1_ptr || p2 == p2_ptr || p2 == p3_ptr || p2 == p4_ptr)
        cont++;
    if (p3 == p1_ptr || p3 == p2_ptr || p3 == p3_ptr || p3 == p4_ptr)
        cont++;
    if (p4 == p1_ptr || p4 == p2_ptr || p4 == p3_ptr || p4 == p4_ptr)
        cont++;

    if (cont == 4)
        return true;

    return false;

}

Punto* Cuadro::getP1() const { return p1; }
void Cuadro::setP1(Punto* p1) { this->p1 = p1;}

Punto* Cuadro::getP2() const{ return p2; }
void Cuadro::setP2(Punto* p2){ this->p2 = p2; }

Punto* Cuadro::getP3() const { return p3; }
void Cuadro::setP3(Punto* p3) { this->p3 = p3; }

Punto* Cuadro::getP4() const { return p4; }
void Cuadro::setP4(Punto* p4) { this->p4 = p4; }

int Cuadro::getJugador() const { return jugador; }
void Cuadro::setJugador(int jugador) { this->jugador = jugador; }