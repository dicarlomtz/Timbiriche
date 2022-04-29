#pragma once
#include "Empresa.h"
#include "Jugada.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Empresa;

class Jugador {

private:

	string cedula;
	string nombre;
	Empresa* empresa;
    Jugada* jugada;
    int numJugador;

public:

	Jugador(string = "", string = "", Empresa* = NULL);
	virtual ~Jugador();

    string getCedula() const;
    void setCedula(string cedula);

    string getNombre() const;
    void setNombre(string nombre);

    Empresa* getEmpresa() const;
    void setEmpresa(Empresa* empresa);

    Jugada* getJugada() const;
    void setJugada(Jugada*);
    bool jugar();

    int getNumJugador() const;
    void setNumJugador(int);

    string getCodigo() const;

    string toString() const;

    friend ostream& operator << (ostream&, const Jugador&);

};