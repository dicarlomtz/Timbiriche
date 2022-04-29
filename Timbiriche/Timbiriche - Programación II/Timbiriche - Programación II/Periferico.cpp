#include "Periferico.h"

Periferico::Periferico(MatrizCampo* m) : Jugada(m) {

	primero = new CapturaPrimero(m);

}

Periferico::~Periferico() {

	delete primero;

}

bool Periferico::realizarJugada(int j) {

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

bool Periferico::verificaArriba(int f, int c, int j) {

	if (f - 1 >= 0 && f - 1 < f)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getArriba() == NULL)
				if (m->getPunto(f - 1, c) != NULL)
					if (m->getPunto(f - 1, c)->getAbajo() == NULL)
						if (!riesgoArriba(f, c)) {

							if (c - 1 == -1 || c + 1 == m->getColumna())
								return true;

							if (c - 1 >= 0)
								if (m->getPunto(f, c - 1) == NULL)
									return true;

							if (c + 1 <= m->getColumna() - 1)
								if (m->getPunto(f, c + 1) == NULL)
									return true;

						}

	return false;

}

bool Periferico::verificaAbajo(int f, int c, int j) {

	if (f + 1 <= m->getFila() - 1 && f + 1 > f)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getAbajo() == NULL)
				if (m->getPunto(f + 1, c) != NULL)
					if (m->getPunto(f + 1, c)->getArriba() == NULL)
						if (!riesgoAbajo(f, c)) {

							if ((c - 1 == -1) || c + 1 == m->getColumna())
								return true;

							if (c - 1 >= 0)
								if (m->getPunto(f, c - 1) == NULL)
									return true;

							if (c + 1 <= m->getColumna() - 1)
								if (m->getPunto(f, c + 1) == NULL)
									return true;

						}
					
	return false;

}

bool Periferico::verificaIzquierda(int f, int c, int j) {

	if (c - 1 >= 0 && c - 1 < c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getIzquierda() == NULL)
				if (m->getPunto(f, c - 1) != NULL)
					if (m->getPunto(f, c - 1)->getDerecha() == NULL)
						if (!riesgoIzquierda(f, c)) {

							if (f - 1 == -1 || f + 1 == m->getFila())
								return true;

							if (f + 1 <= m->getFila() - 1)
								if (m->getPunto(f + 1, c) == NULL)
									return true;

						}

	return false;

}

bool Periferico::verificaDerecha(int f, int c, int j) {

	if (c + 1 <= m->getColumna() - 1 && c + 1 > c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getDerecha() == NULL)
				if (m->getPunto(f, c + 1) != NULL)
					if (m->getPunto(f, c + 1)->getIzquierda() == NULL)
						if (!riesgoDerecha(f, c)) {

							if (f - 1 == -1 || f + 1 == m->getFila())
								return true;

							if (f + 1 <= m->getFila() - 1)
								if (m->getPunto(f + 1, c) == NULL)
									return true;

						}

	return false;

}

//-------------------------------------------------------------------------------

bool Periferico::enlazaArriba(int f, int c, int j) {

	m->getPunto(f, c)->setArriba(m->getPunto(f - 1, c));
	m->getPunto(f - 1, c)->setAbajo(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f - 1, c), j, "arriba"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, -1, 0, j);

	return true;

}

bool Periferico::enlazaAbajo(int f, int c, int j) {

	m->getPunto(f, c)->setAbajo(m->getPunto(f + 1, c));
	m->getPunto(f + 1, c)->setArriba(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f + 1, c), j, "abajo"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 1, 0, j);

	return true;

}

bool Periferico::enlazaIzquierda(int f, int c, int j) {

	m->getPunto(f, c)->setIzquierda(m->getPunto(f, c - 1));
	m->getPunto(f, c - 1)->setDerecha(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c - 1), j, "izquierda"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, -1, j);

	return true;

}

bool Periferico::enlazaDerecha(int f, int c, int j) {

	m->getPunto(f, c)->setDerecha(m->getPunto(f, c + 1));
	m->getPunto(f, c + 1)->setIzquierda(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c + 1), j, "derecha"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, 1, j);

	return true;

}

//-------------------------------------------------------------------------------