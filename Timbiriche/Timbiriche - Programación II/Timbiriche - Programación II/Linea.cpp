#include "Linea.h"

Linea::Linea(Punto* p1, Punto* p2, int jugador, string dire) : 
	p1(p1), p2(p2), jugador(jugador), direP1(dire) {}

Linea::Linea(const Linea& l) {

	this->jugador = l.jugador;
	this->direP1 = l.direP1;

	if (l.p1 != NULL)
		this->p1 = new Punto(*l.p1);
	else
		this->p1 = NULL;

	if (l.p2 != NULL)
		this->p2 = new Punto(*l.p2);
	else
		this->p2 = NULL;

}

Linea::~Linea() {}

bool Linea::conformanLinea(Punto* p1_ptr, Punto* p2_ptr) {

	if (((p1 == p1_ptr) && (p2 == p2_ptr)) || ((p1 == p2_ptr) && (p2 == p1_ptr)))
		return true;

	return false;

}

Punto* Linea::getP1() const { return p1; }
void Linea::setP1(Punto* p1) { this->p1 = p1; }

Punto* Linea::getP2() const { return p2; }
void Linea::setP2(Punto* p2) { this->p2 = p2; }

int Linea::getJugador() const { return jugador; }
void Linea::setJugador(int jugador) { this->jugador = jugador; }


string Linea::getDireP1() const { return direP1; }
void Linea::setDireP1(string direP1) { this->direP1 = direP1; }

Linea& Linea::operator = (const Linea& l) {

	this->jugador = l.jugador;

	if (l.p1 != NULL)
		this->p1 = new Punto(*l.p1);
	else
		this->p1 = NULL;

	if (l.p2 != NULL)
		this->p2 = new Punto(*l.p2);
	else
		this->p2 = NULL;

	return *this;

}

void Linea::guardaLinea(ofstream& out) {

	p1->guardaPunto(out);
	p2->guardaPunto(out);
	out << direP1 << DELIMITA_REGISTRO;
	out << jugador << DELIMITA_REGISTRO;

}

void Linea::leeLinea(ifstream& in) {

	Punto _p1;
	Punto _p2;
	string _d;
	string _j;

	_p1.leePunto(in);
	_p2.leePunto(in);

	getline(in, _d);
	getline(in, _j);

	this->p1 = new Punto(_p1.getFila(), _p1.getColumna());
	this->p2 = new Punto(_p2.getFila(), _p2.getColumna());
	this->direP1 = _d;
	this->jugador = atoi(_j.c_str());

}