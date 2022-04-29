#pragma once
#include "CampoJuego.h"

class ProcesaCompuesto {

private:

	ContenedorV* v;
	MatrizCampo* m;

public:

	ProcesaCompuesto(Contenedor*);
	virtual ~ProcesaCompuesto();

	void pasarInfoVecAMat();

	MatrizCampo* getMatriz();

};