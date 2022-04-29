#include "Islas.h"

Islas::Islas(MatrizCampo* m) : Jugada(m) {

	primero = new CapturaPrimero(m);

}

Islas::~Islas() {

	delete primero;

}

bool Islas::realizarJugada(int j) {

	bool verificar = false;

	this->setCuadroCapturado(false);
	if (!primero->realizarJugada(j)) {

		for (int f = 0; f <= m->getFila() - 1; f++) {

			for (int c = 0; c <= m->getColumna() - 1; c++) {

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

bool Islas::verificaArriba(int f, int c, int j) {

	int cont = 0;

	if (f - 1 >= 0 && f - 1 < f)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getArriba() == NULL)
				if (m->getPunto(f - 1, c) != NULL)
					if (m->getPunto(f - 1, c)->getAbajo() == NULL)
						if (!riesgoArriba(f, c)) {

							if (f > 2) {

								if (c - 1 >= 0)
									if (m->getPunto(f, c - 1) != NULL)
										cont++;

								if (c + 1 <= m->getColumna() - 1)
									if (m->getPunto(f, c + 1) != NULL)
										cont++;

								if (cont == 1)
									return true;

								if (cont >= 2)
									return false;

							}

							if (c % 2 == 0)
								return true;

						}

	return false;

}

bool Islas::verificaAbajo(int f, int c, int j) {

	int cont = 0;

	if (f + 1 <= m->getFila() - 1 && f + 1 > f)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getAbajo() == NULL)
				if (m->getPunto(f + 1, c) != NULL)
					if (m->getPunto(f + 1, c)->getArriba() == NULL)
						if (!riesgoAbajo(f, c)) {

							if (f >= 2) {

								if (c - 1 >= 0)
									if (m->getPunto(f, c - 1) != NULL)
										cont++;

								if (c + 1 <= m->getColumna() - 1)
									if (m->getPunto(f, c + 1) != NULL)
										cont++;

								if (cont == 1)
									return true;

								if (cont >= 2)
									return false;

							}

							if (c % 2 == 0)
								return true;

						}

	return false;

}

bool Islas::verificaIzquierda(int f, int c, int j) {

	int cont = 0;

	if (c - 1 >= 0 && c - 1 < c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getIzquierda() == NULL)
				if (m->getPunto(f, c - 1) != NULL)
					if (m->getPunto(f, c - 1)->getDerecha() == NULL)
						if (!riesgoIzquierda(f, c)) {

							if (c - 1 == m->getColumna() - 2)
								cont++;

							if (c % 2 != 0)
								cont++;

							if (cont == 2)
								return false;

							if (f % 2 == 0)
								return true;

						}

	return false;

}

bool Islas::verificaDerecha(int f, int c, int j) {

	int cont = 0;

	if (c + 1 <= m->getColumna() - 1 && c + 1 > c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getDerecha() == NULL)
				if (m->getPunto(f, c + 1) != NULL)
					if (m->getPunto(f, c + 1)->getIzquierda() == NULL)
						if (!riesgoDerecha(f, c)) {

							if (c + 1 == m->getColumna() - 1)
								cont++;

							if (c + 1 % 2 != 0)
								cont++;

							if (cont == 2)
								return false;

							if (f % 2 == 0)
								return true;

						}

	return false;

}

//-------------------------------------------------------------------------------

bool Islas::enlazaArriba(int f, int c, int j) {

	m->getPunto(f, c)->setArriba(m->getPunto(f - 1, c));
	m->getPunto(f - 1, c)->setAbajo(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f - 1, c), j, "arriba"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, -1, 0, j);

	return true;

}

bool Islas::enlazaAbajo(int f, int c, int j) {

	m->getPunto(f, c)->setAbajo(m->getPunto(f + 1, c));
	m->getPunto(f + 1, c)->setArriba(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f + 1, c), j, "abajo"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 1, 0, j);

	return true;

}

bool Islas::enlazaIzquierda(int f, int c, int j) {

	m->getPunto(f, c)->setIzquierda(m->getPunto(f, c - 1));
	m->getPunto(f, c - 1)->setDerecha(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c - 1), j, "izquierda"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, -1, j);

	return true;

}

bool Islas::enlazaDerecha(int f, int c, int j) {

	m->getPunto(f, c)->setDerecha(m->getPunto(f, c + 1));
	m->getPunto(f, c + 1)->setIzquierda(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c + 1), j, "derecha"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, 1, j);

	return true;

}

//-------------------------------------------------------------------------------