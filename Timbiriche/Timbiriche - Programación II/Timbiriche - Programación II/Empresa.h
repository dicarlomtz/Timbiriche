#pragma once
#include "Jugador.h"
#include "Lista.h"
#include "Partida.h"
#include "NumeroAleatorio.h"
#include "Utiles.h"

using namespace std;

class Jugador;

class Empresa {

private:

	string nombre;
	Lista<Jugador>* jugadores;
	Lista<Partida>* partidas;
	string codigo;
	string clave;

public:

	Empresa(string);
	virtual ~Empresa();
	void attach(Jugador*);
	string getCodigo() const;
	void generaCodigo();
	string getClave() const;
	void setClave(string);
	bool jugadorRepetido(string);
	Jugador* getJugador(string);
	bool otroJugador(string);
	void imprimeJugadores();
	void guardarPartidas();
	void cargarPartidas();
	void agregarPartidas(Partida*);
	Lista<Partida>* getPartidas() const;
	void setPartidas(Lista<Partida>*);
	string imprimePartidas();
	Partida* getPartida(int);

};