#include "Cercano.h"

Cercano::Cercano(MatrizCampo* m) : Jugada(m) {

	primero = new CapturaPrimero(m);

}

Cercano::~Cercano() {

	delete primero;

}

bool Cercano::realizarJugada(int j) {

	this->setCuadroCapturado(false);
	if (!primero->realizarJugada(j)) {

		for (int f = 0; f <= m->getFila() - 1; f++) {

			for (int c = 0; c <= m->getColumna() - 1; c++) {

				//-----------------------------------------------------------------------------------------------

				if (verificaArriba(f, c, j))
					return enlazaArriba(f, c, j);

				//-----------------------------------------------------------------------------------------------

				if (verificaAbajo(f, c, j))
					return enlazaAbajo(f, c, j);

				//-----------------------------------------------------------------------------------------------

				if (verificaIzquierda(f, c, j))
					return enlazaIzquierda(f, c, j);

				//-----------------------------------------------------------------------------------------------

				if (verificaDerecha(f, c, j))
					return enlazaDerecha(f, c, j);

				//-----------------------------------------------------------------------------------------------

			}

		}

	}
	else {

		setCuadroCapturado(true);
		return true;

	}

	return false;

}

//-------------------------------------------------------------------------------

bool Cercano::verificaArriba(int f, int c, int j) {

	int cont1 = 0, cont2 = 0;

	if (f - 1 >= 0 && f - 1 < f)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getArriba() == NULL)
				if (m->getPunto(f - 1, c) != NULL)
					if (m->getPunto(f - 1, c)->getAbajo() == NULL)
						if ((m->getPunto(f, c)->getJugador1Posicionado() && j == 2) || (m->getPunto(f, c)->getJugador2Posicionado() && j == 1))
							if (!riesgoArriba(f, c))
								return true;
	return false;

}

bool Cercano::verificaAbajo(int f, int c, int j) {

	int cont1 = 0, cont2 = 0;

	if (f + 1 <= m->getFila() - 1 && f + 1 > f)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getAbajo() == NULL)
				if (m->getPunto(f + 1, c) != NULL)
					if (m->getPunto(f + 1, c)->getArriba() == NULL)
						if ((m->getPunto(f, c)->getJugador1Posicionado() && j == 2) || (m->getPunto(f, c)->getJugador2Posicionado() && j == 1))
							if (!riesgoAbajo(f, c))
								return true;

	return false;

}

bool Cercano::verificaIzquierda(int f, int c, int j) {

	int cont1 = 0, cont2 = 0;

	if (c - 1 >= 0 && c - 1 < c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getIzquierda() == NULL)
				if (m->getPunto(f, c - 1) != NULL)
					if (m->getPunto(f, c - 1)->getDerecha() == NULL)
						if ((m->getPunto(f, c)->getJugador1Posicionado() && j == 2) || (m->getPunto(f, c)->getJugador2Posicionado() && j == 1))
							if (!riesgoIzquierda(f, c))
								return true;

	return false;

}

bool Cercano::verificaDerecha(int f, int c, int j) {

	int cont1 = 0, cont2 = 0;

	if (c + 1 <= m->getColumna() - 1 && c + 1 > c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getDerecha() == NULL)
				if (m->getPunto(f, c + 1) != NULL)
					if (m->getPunto(f, c + 1)->getIzquierda() == NULL)
						if ((m->getPunto(f, c)->getJugador1Posicionado() && j == 2) || (m->getPunto(f, c)->getJugador2Posicionado() && j == 1))
							if (!riesgoDerecha(f, c))
								return true;

	return false;

}

//-------------------------------------------------------------------------------

bool Cercano::enlazaArriba(int f, int c, int j) {

	m->getPunto(f, c)->setArriba(m->getPunto(f - 1, c));
	m->getPunto(f - 1, c)->setAbajo(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f - 1, c), j, "arriba"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, -1, 0, j);

	return true;

}

bool Cercano::enlazaAbajo(int f, int c, int j) {

	m->getPunto(f, c)->setAbajo(m->getPunto(f + 1, c));
	m->getPunto(f + 1, c)->setArriba(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f + 1, c), j, "abajo"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 1, 0, j);

	return true;

}

bool Cercano::enlazaIzquierda(int f, int c, int j) {

	m->getPunto(f, c)->setIzquierda(m->getPunto(f, c - 1));
	m->getPunto(f, c - 1)->setDerecha(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c - 1), j, "izquierda"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, -1, j);

	return true;

}

bool Cercano::enlazaDerecha(int f, int c, int j) {

	m->getPunto(f, c)->setDerecha(m->getPunto(f, c + 1));
	m->getPunto(f, c + 1)->setIzquierda(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c + 1), j, "derecha"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, 1, j);

	return true;

}

//-------------------------------------------------------------------------------