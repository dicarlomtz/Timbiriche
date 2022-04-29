#include "Central.h"

Central::Central(MatrizCampo* m) : Jugada(m) {

	primero = new CapturaPrimero(m);

}

Central::~Central() {

	delete m;

}

//-------------------------------------------------------------------------------

bool Central::realizarJugada(int j) {

	this->setCuadroCapturado(false);
	if (!primero->realizarJugada(j)) {

		for (int f = 1; f <= m->getFila() - 2; f++) {

			for (int c = 1; c <= m->getColumna() - 2; c++) {

				//---------------------------------------------------------------------------------------

				if (verificaArriba(f, c, j))
					return enlazaArriba(f, c, j);

				//---------------------------------------------------------------------------------------

				if (verificaAbajo(f, c, j))
					return enlazaAbajo(f, c, j);

				//---------------------------------------------------------------------------------------

				if (verificaIzquierda(f, c, j))
					return enlazaIzquierda(f, c, j);

				//---------------------------------------------------------------------------------------

				if (verificaDerecha(f, c, j))
					return enlazaDerecha(f, c, j);

				//---------------------------------------------------------------------------------------

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

bool Central::verificaArriba(int f, int c, int j) {

	if (f - 1 >= 0 && f - 1 < f)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getArriba() == NULL)
				if (m->getPunto(f - 1, c) != NULL)
					if (m->getPunto(f - 1, c)->getAbajo() == NULL)
						if (!riesgoArriba(f, c)) {

							for (int j = 0; j < m->getColumna() - 1; j++)
								if (m->getPunto(f, j) == NULL)
									return false;

							for (int j = 0; j < m->getColumna() - 1; j++)
								if (m->getPunto(f + 1, j) == NULL)
									return false;

							return true;

						}

	return false;

}

bool Central::verificaAbajo(int f, int c, int j) {

	if (f + 1 <= m->getFila() - 1 && f + 1 > f)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getAbajo() == NULL)
				if (m->getPunto(f + 1, c) != NULL)
					if (m->getPunto(f + 1, c)->getArriba() == NULL)
						if (!riesgoAbajo(f, c)) {

							for (int j = 0; j < m->getColumna() - 1; j++)
								if (m->getPunto(f, j) == NULL)
									return false;

							for (int j = 0; j < m->getColumna() - 1; j++)
								if (m->getPunto(f + 1, j) == NULL)
									return false;

							return true;

						}

	return false;

}

bool Central::verificaIzquierda(int f, int c, int j) {


	if (c - 1 >= 0 && c - 1 < c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getIzquierda() == NULL)
				if (m->getPunto(f, c - 1) != NULL)
					if (m->getPunto(f, c - 1)->getDerecha() == NULL)
						if (!riesgoIzquierda(f, c)) {

							for (int j = 0; j < m->getColumna() - 1; j++)
								if (m->getPunto(f, j) == NULL)
									return false;

							for (int j = 0; j < m->getColumna() - 1; j++)
								if (m->getPunto(f + 1, j) == NULL)
									return false;

							return true;

						}
	
	return false;

}

bool Central::verificaDerecha(int f, int c, int j) {

	if (c + 1 <= m->getColumna() - 1 && c + 1 > c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getDerecha() == NULL)
				if (m->getPunto(f, c + 1) != NULL)
					if (m->getPunto(f, c + 1)->getIzquierda() == NULL)
						if (!riesgoDerecha(f, c)) {

							for (int j = 0; j < m->getColumna() - 1; j++)
								if (m->getPunto(f, j) == NULL)
									return false;
						
							for (int j = 0; j < m->getColumna() - 1; j++)
								if (m->getPunto(f + 1, j) == NULL)
									return false;

							return true;

						}

	return false;

}

//-------------------------------------------------------------------------------


bool Central::enlazaArriba(int f, int c, int j) {

	m->getPunto(f, c)->setArriba(m->getPunto(f - 1, c));
	m->getPunto(f - 1, c)->setAbajo(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f - 1, c), j, "arriba"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, -1, 0, j);

	return true;

}

bool Central::enlazaAbajo(int f, int c, int j) {

	m->getPunto(f, c)->setAbajo(m->getPunto(f + 1, c));
	m->getPunto(f + 1, c)->setArriba(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f + 1, c), j, "abajo"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 1, 0, j);

	return true;

}

bool Central::enlazaIzquierda(int f, int c, int j) {

	m->getPunto(f, c)->setIzquierda(m->getPunto(f, c - 1));
	m->getPunto(f, c - 1)->setDerecha(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c - 1), j, "izquierda"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, -1, j);

	return true;

}

bool Central::enlazaDerecha(int f, int c, int j) {

	m->getPunto(f, c)->setDerecha(m->getPunto(f, c + 1));
	m->getPunto(f, c + 1)->setIzquierda(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c + 1), j, "derecha"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, 1, j);

	return true;

}

//-------------------------------------------------------------------------------