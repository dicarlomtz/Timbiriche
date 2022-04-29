#include "Jugador.h"

Jugador::Jugador(string ced, string nom, Empresa* em) : 
	cedula(ced), nombre(nom), empresa(em) {

	jugada = NULL;
	numJugador = 0;

	if (empresa != NULL)
		empresa->attach(this);

}

Jugador::~Jugador() {

	delete jugada;

}

string Jugador::getCedula() const { return cedula; }
void Jugador::setCedula(string cedula) { this->cedula = cedula; }

string Jugador::getNombre() const { return nombre; }
void Jugador::setNombre(string nombre) { this->nombre = nombre; }

Empresa* Jugador::getEmpresa() const { return empresa; }
void Jugador::setEmpresa(Empresa* empresa) { this->empresa = empresa; }

Jugada* Jugador::getJugada() const { return jugada; }
void Jugador::setJugada(Jugada* jugada) { this->jugada = jugada; }
bool Jugador::jugar() { return jugada->realizarJugada(numJugador); }

int Jugador::getNumJugador() const { return numJugador; }
void Jugador::setNumJugador(int numJugador) { this->numJugador = numJugador; }

string Jugador::getCodigo() const { return empresa->getCodigo(); }

string Jugador::toString() const {

	stringstream s;

	s << "Cedula: " << cedula << endl
		<< "Nombre: " << nombre << endl
		<< "Codigo adquirido: " << this->getCodigo() << endl;

	return s.str();

}

ostream& operator << (ostream& out, const Jugador& j) {

	return out << "Cedula: " << j.cedula << endl
		<< "Nombre: " << j.nombre << endl;

}