#pragma once
#include "CampoAbstracto.h"

class CampoQuincePuntos : public CampoAbstracto {

private:

	MatrizCampo* m;

public:

	CampoQuincePuntos();
	virtual ~CampoQuincePuntos();

	Contenedor* getContenedor();

};