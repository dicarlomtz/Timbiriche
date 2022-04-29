#include "Aleatorio.h"

Aleatorio::Aleatorio(MatrizCampo* m) : Jugada(m) {

	primero = new CapturaPrimero(m);

}

Aleatorio::~Aleatorio() {

	delete primero;

}

bool Aleatorio::realizarJugada(int j) {

	this->setCuadroCapturado(false);
	if (!primero->realizarJugada(j)) {

		if (!accionaJugada(j)) {

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

			return true;

		}

	}
	else {

		setCuadroCapturado(true);
		return true;

	}

	return false;

}

//-------------------------------------------------------------------------------

bool Aleatorio::verificaArriba(int f, int c, int j) {

	if (f - 1 >= 0 && f - 1 < f)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getArriba() == NULL)
				if (m->getPunto(f - 1, c) != NULL)
					if (m->getPunto(f - 1, c)->getAbajo() == NULL)
						return true;

	return false;

}

bool Aleatorio::verificaAbajo(int f, int c, int j) {

		if (f + 1 <= m->getFila() - 1 && f + 1 > f)
			if (m->getPunto(f, c) != NULL)
				if (m->getPunto(f, c)->getAbajo() == NULL)
					if (m->getPunto(f + 1, c) != NULL)
						if (m->getPunto(f + 1, c)->getArriba() == NULL)
							return true;

	return false;

}

bool Aleatorio::verificaIzquierda(int f, int c, int j) {

	if (c - 1 >= 0 && c - 1 < c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getIzquierda() == NULL)
				if (m->getPunto(f, c - 1) != NULL)
					if (m->getPunto(f, c - 1)->getDerecha() == NULL)
						return true;

	return false;

}

bool Aleatorio::verificaDerecha(int f, int c, int j) {

	if (c + 1 <= m->getColumna() - 1 && c + 1 > c)
		if (m->getPunto(f, c) != NULL)
			if (m->getPunto(f, c)->getDerecha() == NULL)
				if (m->getPunto(f, c + 1) != NULL)
					if (m->getPunto(f, c + 1)->getIzquierda() == NULL)
						return true;

	return false;

}

//-------------------------------------------------------------------------------

bool Aleatorio::enlazaArriba(int f, int c, int j) {

	m->getPunto(f, c)->setArriba(m->getPunto(f - 1, c));
	m->getPunto(f - 1, c)->setAbajo(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f - 1, c), j, "arriba"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, -1, 0, j);

	return true;

}

bool Aleatorio::enlazaAbajo(int f, int c, int j) {

	m->getPunto(f, c)->setAbajo(m->getPunto(f + 1, c));
	m->getPunto(f + 1, c)->setArriba(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f + 1, c), j, "abajo"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 1, 0, j);

	return true;

}

bool Aleatorio::enlazaIzquierda(int f, int c, int j) {

	m->getPunto(f, c)->setIzquierda(m->getPunto(f, c - 1));
	m->getPunto(f, c - 1)->setDerecha(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c - 1), j, "izquierda"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, -1, j);

	return true;

}

bool Aleatorio::enlazaDerecha(int f, int c, int j) {

	m->getPunto(f, c)->setDerecha(m->getPunto(f, c + 1));
	m->getPunto(f, c + 1)->setIzquierda(m->getPunto(f, c));

	m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c + 1), j, "derecha"));

	posicionarJugador(f, c, 0, 0, j);
	posicionarJugador(f, c, 0, 1, j);

	return true;

}

//-------------------------------------------------------------------------------

bool Aleatorio::verificaAleatorio(int f, int c, int dire) {

	if (m->getPunto(f, c) != NULL) {

		switch (dire) {
		
		case 1: return verificaArriba(f, c, 0); break;
		case 2: return verificaAbajo(f, c, 0); break;
		case 3: return verificaIzquierda(f, c, 0); break;
		case 4: return verificaDerecha(f, c, 0); break;

		}

	}

	return false;

}

bool Aleatorio::enlazaAleatorio(int f, int c, int dire, int j) {

	switch (dire) {

	case 1: return enlazaArriba(f, c, j); break;
	case 2: return enlazaAbajo(f, c, j); break;
	case 3: return enlazaIzquierda(f, c, j); break;
	case 4: return enlazaDerecha(f, c, j); break;

	}

	return false;

}

bool Aleatorio::accionaJugada(int j) {

	int f = 0, c = 0, dire = 0, cont = 5;
	NumeroAleatorio num;

	while (cont > 0) {

		f = num.numeroAleatorio(1, m->getFila() - 1) - 1;
		c = num.numeroAleatorio(1, m->getColumna() - 1) - 1;
		dire = num.numeroAleatorio(1, 4);

		if (verificaAleatorio(f, c, dire))
			return enlazaAleatorio(f, c, dire, j);

		cont--;
	}

	return false;

}

//-------------------------------------------------------------------------------