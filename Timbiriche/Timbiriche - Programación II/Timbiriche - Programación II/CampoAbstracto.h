#pragma once
#include "MatrizCampo.h"

class CampoAbstracto {

protected:

	string codigo;

public:

	CampoAbstracto() {}
	virtual ~CampoAbstracto() {}

	string getCodigo() const { return codigo; }

	virtual Contenedor* getContenedor() = 0;

};