#pragma once
#include "CampoAbstracto.h"
#include "ContenedorV.h"

class CampoJuego : public CampoAbstracto {

private:

	ContenedorV* v;

public:

	CampoJuego(int = 0);
	virtual ~CampoJuego();
	void ingresaCampo(CampoAbstracto*);
	Contenedor* getContenedor();

};