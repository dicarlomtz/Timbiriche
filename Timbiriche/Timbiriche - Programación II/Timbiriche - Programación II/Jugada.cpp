#include "Jugada.h"

Jugada::Jugada(MatrizCampo* m) : m(m) {

	this->cuadroCapturado = false;

}

Jugada::~Jugada() {}

void Jugada::setCuadroCapturado(bool ptr) { this->cuadroCapturado = ptr; }
bool Jugada::getCuadroCapturado() const { return cuadroCapturado; }

//-------------------------------------------------------------------------------

bool Jugada::masJugadas() {

	for (int i = 0; i < m->getFila(); i++) {

		for (int j = 0; j < m->getColumna(); j++) {

			if (m->getPunto(i, j) != NULL) {

				if (i != 0) {
					if (m->getPunto(i, j)->getArriba() == NULL) {
						return true;

					}

				}

				if (j != m->getColumna() - 1) {

					if (m->getPunto(i, j + 1) != NULL) {

						if (m->getPunto(i, j)->getDerecha() == NULL) {
							return true;

						}

					}

				}

			}

		}

	}

	return false;

}

//-------------------------------------------------------------------------------

void Jugada::posicionarJugador(int f, int c, int fsuma, int csuma, int j) {

	if (j == 1) {

		m->getPunto(f + fsuma, c + csuma)->setJugador1Posicionado(true);

	}
	else {

		m->getPunto(f + fsuma, c + csuma)->setJugador2Posicionado(true);

	}

}

//-------------------------------------------------------------------------------

bool Jugada::riesgoArriba(int f, int c) {

	int cont1 = 0, cont2 = 0;

	if (m->getPunto(f, c)->getIzquierda() != NULL) {
		cont1++;

		if (m->getPunto(f, c)->getIzquierda()->getArriba() != NULL)
			cont1++;

	}
	if (m->getPunto(f - 1, c)->getIzquierda() != NULL) {
		cont1++;

		if (m->getPunto(f - 1, c)->getIzquierda()->getAbajo() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c)->getDerecha() != NULL) {
		cont2++;

		if (m->getPunto(f, c)->getDerecha()->getArriba() != NULL)
			cont2++;

	}
	if (m->getPunto(f - 1, c)->getDerecha() != NULL) {
		cont2++;

		if (m->getPunto(f - 1, c)->getDerecha()->getAbajo() != NULL)
			cont2++;

	}

	if (cont1 > 1 || cont2 > 1)
		return true;

	return false;

}

bool Jugada::riesgoAbajo(int f, int c) {

	int cont1 = 0, cont2 = 0;

	if (m->getPunto(f, c)->getIzquierda() != NULL) {
		cont1++;

		if (m->getPunto(f, c)->getIzquierda()->getAbajo() != NULL)
			cont1++;

	}
	if (m->getPunto(f + 1, c)->getIzquierda() != NULL) {
		cont1++;

		if (m->getPunto(f + 1, c)->getIzquierda()->getArriba() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c)->getDerecha() != NULL) {
		cont2++;

		if (m->getPunto(f, c)->getDerecha()->getAbajo() != NULL)
			cont2++;

	}
	if (m->getPunto(f + 1, c)->getDerecha() != NULL) {
		cont2++;

		if (m->getPunto(f + 1, c)->getDerecha()->getArriba() != NULL)
			cont2++;

	}

	if (cont1 > 1 || cont2 > 1)
		return true;

	return false;

}

bool Jugada::riesgoIzquierda(int f, int c) {

	int cont1 = 0, cont2 = 0;

	if (m->getPunto(f, c)->getAbajo() != NULL) {
		cont1++;

		if (m->getPunto(f, c)->getAbajo()->getIzquierda() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c - 1)->getAbajo() != NULL) {
		cont1++;

		if (m->getPunto(f, c - 1)->getAbajo()->getDerecha() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c)->getArriba() != NULL) {
		cont2++;

		if (m->getPunto(f, c)->getArriba()->getIzquierda() != NULL)
			cont2++;

	}
	if (m->getPunto(f, c - 1)->getArriba() != NULL) {
		cont2++;

		if (m->getPunto(f, c - 1)->getArriba()->getDerecha() != NULL)
			cont2++;

	}

	if (cont1 > 1 || cont2 > 1)
		return true;

	return false;

}

bool Jugada::riesgoDerecha(int f, int c) {

	int cont1 = 0, cont2 = 0;

	if (m->getPunto(f, c)->getAbajo() != NULL) {
		cont1++;

		if (m->getPunto(f, c)->getAbajo()->getDerecha() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c + 1)->getAbajo() != NULL) {
		cont1++;

		if (m->getPunto(f, c + 1)->getAbajo()->getIzquierda() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c)->getArriba() != NULL) {
		cont2++;

		if (m->getPunto(f, c)->getArriba()->getDerecha() != NULL)
			cont2++;

	}
	if (m->getPunto(f, c + 1)->getArriba() != NULL) {
		cont2++;

		if (m->getPunto(f, c + 1)->getArriba()->getIzquierda() != NULL)
			cont2++;

	}

	if (cont1 > 1 || cont2 > 1)
		return true;

	return false;

}

//-------------------------------------------------------------------------------

void Jugada::cuadroArriba(int f, int c, int j) {

	int cont1 = 0, cont2 = 0; 

	if (m->getPunto(f, c)->getIzquierda() != NULL) {
		cont1++;

		if (m->getPunto(f, c)->getIzquierda()->getArriba() != NULL)
			cont1++;

	}
	if (m->getPunto(f - 1, c)->getIzquierda() != NULL) {
		cont1++;

		if (m->getPunto(f - 1, c)->getIzquierda()->getAbajo() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c)->getDerecha() != NULL) {
		cont2++;

		if (m->getPunto(f, c)->getDerecha()->getArriba() != NULL)
			cont2++;

	}
	if (m->getPunto(f - 1, c)->getDerecha() != NULL) {
		cont2++;

		if (m->getPunto(f - 1, c)->getDerecha()->getAbajo() != NULL)
			cont2++;

	}

	if (cont1 == 4) {

		m->getCuadros()->ingresaDePrimero(new Cuadro(m->getPunto(f, c), m->getPunto(f - 1, c), m->getPunto(f - 1, c - 1), m->getPunto(f, c - 1), j));

	}

	if (cont2 == 4) {

		m->getCuadros()->ingresaDePrimero(new Cuadro(m->getPunto(f, c), m->getPunto(f - 1, c), m->getPunto(f - 1, c + 1), m->getPunto(f, c + 1), j));

	}

}

void Jugada::cuadroAbajo(int f, int c, int j) {

	int cont1 = 0, cont2 = 0;

	if (m->getPunto(f, c)->getIzquierda() != NULL) {
		cont1++;

		if (m->getPunto(f, c)->getIzquierda()->getAbajo() != NULL)
			cont1++;

	}
	if (m->getPunto(f + 1, c)->getIzquierda() != NULL) {
		cont1++;

		if (m->getPunto(f + 1, c)->getIzquierda()->getArriba() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c)->getDerecha() != NULL) {
		cont2++;

		if (m->getPunto(f, c)->getDerecha()->getAbajo() != NULL)
			cont2++;

	}
	if (m->getPunto(f + 1, c)->getDerecha() != NULL) {
		cont2++;

		if (m->getPunto(f + 1, c)->getDerecha()->getArriba() != NULL)
			cont2++;

	}

	if (cont1 == 4) {

		m->getCuadros()->ingresaDePrimero(new Cuadro(m->getPunto(f, c), m->getPunto(f + 1, c), m->getPunto(f + 1, c - 1), m->getPunto(f, c - 1), j));

	}

	if (cont2 == 4) {

		m->getCuadros()->ingresaDePrimero(new Cuadro(m->getPunto(f, c), m->getPunto(f + 1, c), m->getPunto(f + 1, c + 1), m->getPunto(f, c + 1), j));

	}

}

void Jugada::cuadroIzquierda(int f, int c, int j) {

	int cont1 = 0, cont2 = 0;

	if (m->getPunto(f, c)->getAbajo() != NULL) {
		cont1++;

		if (m->getPunto(f, c)->getAbajo()->getIzquierda() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c - 1)->getAbajo() != NULL) {
		cont1++;

		if (m->getPunto(f, c - 1)->getAbajo()->getDerecha() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c)->getArriba() != NULL) {
		cont2++;

		if (m->getPunto(f, c)->getArriba()->getIzquierda() != NULL)
			cont2++;

	}
	if (m->getPunto(f, c - 1)->getArriba() != NULL) {
		cont2++;

		if (m->getPunto(f, c - 1)->getArriba()->getDerecha() != NULL)
			cont2++;

	}

	if (cont1 == 4) {

		m->getCuadros()->ingresaDePrimero(new Cuadro(m->getPunto(f, c), m->getPunto(f + 1, c), m->getPunto(f + 1, c - 1), m->getPunto(f, c - 1), j));

	}

	if (cont2 == 4) {

		m->getCuadros()->ingresaDePrimero(new Cuadro(m->getPunto(f, c), m->getPunto(f - 1, c), m->getPunto(f - 1, c - 1), m->getPunto(f, c - 1), j));

	}

}

void Jugada::cuadroDerecha(int f, int c, int j) {

	int cont1 = 0, cont2 = 0;

	if (m->getPunto(f, c)->getAbajo() != NULL) {
		cont1++;

		if (m->getPunto(f, c)->getAbajo()->getDerecha() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c + 1)->getAbajo() != NULL) {
		cont1++;

		if (m->getPunto(f, c + 1)->getAbajo()->getIzquierda() != NULL)
			cont1++;

	}
	if (m->getPunto(f, c)->getArriba() != NULL) {
		cont2++;

		if (m->getPunto(f, c)->getArriba()->getDerecha() != NULL)
			cont2++;

	}
	if (m->getPunto(f, c + 1)->getArriba() != NULL) {
		cont2++;

		if (m->getPunto(f, c + 1)->getArriba()->getIzquierda() != NULL)
			cont2++;

	}

	if (cont1 == 4) {

		m->getCuadros()->ingresaDePrimero(new Cuadro(m->getPunto(f, c), m->getPunto(f + 1, c), m->getPunto(f + 1, c + 1), m->getPunto(f, c + 1), j));

	}

	if (cont2 == 4) {

		m->getCuadros()->ingresaDePrimero(new Cuadro(m->getPunto(f, c), m->getPunto(f - 1, c), m->getPunto(f - 1, c + 1), m->getPunto(f, c + 1), j));

	}

}