#include "CampoNuevePuntos.h"

CampoNuevePuntos::CampoNuevePuntos() {

	codigo = "NuevePuntos";
	m = new MatrizCampo(3, 3);

}

CampoNuevePuntos::~CampoNuevePuntos() {

	delete m;

}

Contenedor* CampoNuevePuntos::getContenedor() {

	return m;

}