#pragma once
#include "CampoAbstracto.h"

class CampoNuevePuntos : public CampoAbstracto {

private:

	MatrizCampo* m;

public:

	CampoNuevePuntos();
	virtual ~CampoNuevePuntos();

	Contenedor* getContenedor();

};