#include "ColocaLineasCuadros.h"

//-------------------------------------------------------------------------------

bool ColocaLineasCuadros::enlazaArriba(int f, int c, int j, MatrizCampo* m) {

	cuadroArriba(f, c, j, m);

	m->getPunto(f, c)->setArriba(m->getPunto(f - 1, c));
	m->getPunto(f - 1, c)->setAbajo(m->getPunto(f, c));

	m->getLineas()->ingresaDePrimero(new Linea(m->getPunto(f, c), m->getPunto(f - 1, c), j, "arriba"));

	posicionarJugador(f, c, 0, 0, j, m);
	posicionarJugador(f, c, -1, 0, j, m);

	return true;

}

bool ColocaLineasCuadros::enlazaAbajo(int f, int c, int j, MatrizCampo* m) {

	cuadroAbajo(f, c, j, m);

	m->getPunto(f, c)->setAbajo(m->getPunto(f + 1, c));
	m->getPunto(f + 1, c)->setArriba(m->getPunto(f, c));

	m->getLineas()->ingresaDePrimero(new Linea(m->getPunto(f, c), m->getPunto(f + 1, c), j, "abajo"));

	posicionarJugador(f, c, 0, 0, j, m);
	posicionarJugador(f, c, 1, 0, j, m);

	return true;

}

bool ColocaLineasCuadros::enlazaIzquierda(int f, int c, int j, MatrizCampo* m) {

	cuadroIzquierda(f, c, j, m);

	m->getPunto(f, c)->setIzquierda(m->getPunto(f, c - 1));
	m->getPunto(f, c - 1)->setDerecha(m->getPunto(f, c));

	m->getLineas()->ingresaDePrimero(new Linea(m->getPunto(f, c), m->getPunto(f, c - 1), j, "izquierda"));

	posicionarJugador(f, c, 0, 0, j, m);
	posicionarJugador(f, c, 0, -1, j, m);

	return true;

}

bool ColocaLineasCuadros::enlazaDerecha(int f, int c, int j, MatrizCampo* m) {

	cuadroDerecha(f, c, j, m);

	m->getPunto(f, c)->setDerecha(m->getPunto(f, c + 1));
	m->getPunto(f, c + 1)->setIzquierda(m->getPunto(f, c));

	m->getLineas()->ingresaDePrimero(new Linea(m->getPunto(f, c), m->getPunto(f, c + 1), j, "derecha"));

	posicionarJugador(f, c, 0, 0, j, m);
	posicionarJugador(f, c, 0, 1, j, m);

	return true;

}

//-------------------------------------------------------------------------------

void ColocaLineasCuadros::cuadroArriba(int f, int c, int j, MatrizCampo* m) {

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

void ColocaLineasCuadros::cuadroAbajo(int f, int c, int j, MatrizCampo* m) {

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

void ColocaLineasCuadros::cuadroIzquierda(int f, int c, int j, MatrizCampo* m) {

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

void ColocaLineasCuadros::cuadroDerecha(int f, int c, int j, MatrizCampo* m) {

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

//-------------------------------------------------------------------------------

void ColocaLineasCuadros::posicionarJugador(int f, int c, int fsuma, int csuma, int j, MatrizCampo* m) {

	if (j == 1) {

		m->getPunto(f + fsuma, c + csuma)->setJugador1Posicionado(true);

	}
	else {

		m->getPunto(f + fsuma, c + csuma)->setJugador2Posicionado(true);

	}

}

//-------------------------------------------------------------------------------
