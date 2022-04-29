#include "CampoQuincePuntos.h"

CampoQuincePuntos::CampoQuincePuntos() {

	this->codigo = "QuincePuntos";
	
	m = new MatrizCampo(5, 3);

}

CampoQuincePuntos::~CampoQuincePuntos() {

	delete m;

}

Contenedor* CampoQuincePuntos::getContenedor() {

	return m;

}