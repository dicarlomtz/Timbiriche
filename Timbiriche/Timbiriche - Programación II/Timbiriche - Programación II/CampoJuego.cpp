#include "CampoJuego.h"

CampoJuego::CampoJuego(int tam) {

	v = new ContenedorV(tam);

}

CampoJuego::~CampoJuego() {}

void CampoJuego::ingresaCampo(CampoAbstracto* campo) {

	v->agregaCampo(campo);

}

Contenedor* CampoJuego::getContenedor() {

	return v;

}