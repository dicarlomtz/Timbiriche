#include "ContenedorV.h"

ContenedorV::ContenedorV(int tam) {

	this->tam = tam;
	can = 0;

	v = new CampoAbstracto * [tam];

	for (int i = 0; i < tam; i++)
		v[i] = NULL;

}

ContenedorV::~ContenedorV() {

	for (int i = 0; i < tam; i++)
		delete v[i];

}

void ContenedorV::agregaCampo(CampoAbstracto* c) {

	if (can < tam)
		v[can++] = c;

}

int ContenedorV::getCan()  const { return can; }
int ContenedorV::getTam() const { return tam; }

CampoAbstracto* ContenedorV::getPos(int p) {

	if (p < can)
		return v[p];

	return NULL;

}