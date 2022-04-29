#include "CampoSeisPuntos.h"

CampoSeisPuntos::CampoSeisPuntos() {

	this->codigo = "SeisPuntos";
	
	m = new MatrizCampo(3, 2);

}

CampoSeisPuntos::~CampoSeisPuntos() {

	delete m;

}

Contenedor* CampoSeisPuntos::getContenedor() {

	return m;

}