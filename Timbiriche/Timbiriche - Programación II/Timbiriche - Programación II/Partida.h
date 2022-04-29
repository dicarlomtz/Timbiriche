#pragma once
#include "MatrizCampo.h"
#include "CampoJuego.h"
#include "ProcesaCompuesto.h"
#include "CampoSeisPuntos.h"
#include "CampoNuevePuntos.h"
#include "CampoQuincePuntos.h"
#include "ColocaLineasCuadros.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
#include <string>

class Partida {

private:

	string jugador1;
	string jugador2;
	Lista<string>* campos;
	Lista<Linea>* lineas;
	Lista<Cuadro>* cuadros;
	CampoJuego* campo;
	MatrizCampo* m;

public:

	Partida(Lista<Linea>* = new Lista<Linea>, Lista<string>* = new Lista<string>, string = "", string = "");
	virtual ~Partida();

	Lista<string>* getCampos() const;
	void setCampos(Lista<string>*);

	Lista<Linea>* getLineas() const;
	void setLineas(Lista<Linea>*);

	Lista<Cuadro>* getCuadros() const;
	void setCuadros(Lista<Cuadro>*);

	CampoJuego* getCampo() const;
	void setCampo(CampoJuego*);

	MatrizCampo* getMatrizCampo() const;
	void setMatrizCampo(MatrizCampo*);

	string getJugador1() const;
	void setJugador1(string);

	string getJugador2() const;
	void setJugador2(string);

	void procesaMatrizCampo();

	void replicaPartida();

	friend ostream& operator << (ostream&, const Partida&);

	void guardaPartida(ofstream&);
	void leePartida(ifstream&);

};