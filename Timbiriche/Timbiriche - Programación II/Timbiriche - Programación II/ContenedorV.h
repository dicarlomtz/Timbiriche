#pragma once
#include "CampoAbstracto.h"
#include "Contenedor.h"

class ContenedorV : public Contenedor {

private:

	int tam;
	int can;
	CampoAbstracto** v;

public:

	ContenedorV(int);
	virtual ~ContenedorV();

	void agregaCampo(CampoAbstracto*);

	int getCan() const;
	int getTam() const;
	CampoAbstracto* getPos(int);

};