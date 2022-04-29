#pragma once
#include "CampoAbstracto.h"

class CampoSeisPuntos : public CampoAbstracto {

private:

	MatrizCampo* m;

public:

	CampoSeisPuntos();
	virtual ~CampoSeisPuntos();

	Contenedor* getContenedor();

};