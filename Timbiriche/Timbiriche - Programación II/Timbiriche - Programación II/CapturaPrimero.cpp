#include "CapturaPrimero.h"

CapturaPrimero::CapturaPrimero(MatrizCampo* m) : Jugada(m) {}
CapturaPrimero::~CapturaPrimero() {}

bool CapturaPrimero::realizarJugada(int j) {

	for (int f = 0; f <= m->getFila() - 1; f++) { //Recorre filas de la matriz

		for (int c = 0; c <= m->getColumna() - 1; c++) { //Recorre columnas de la matriz

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

	return false;

}

//-------------------------------------------------------------------------------

bool CapturaPrimero::verificaArriba(int f, int c, int j) {

	int cont = 0;

	if (f - 1 >= 0 && f - 1 < f)
		if (m->getPunto(f, c) != NULL)
			if (c + 1 <= m->getColumna() - 1 && c + 1 > c)
				if (m->getPunto(f - 1, c + 1) != NULL)
					if (m->getPunto(f, c + 1) != NULL)
						if (m->getPunto(f - 1, c) != NULL) {

							if (m->getPunto(f, c)->getArriba() == NULL)
								cont++;
							if (m->getPunto(f - 1, c)->getDerecha() == NULL)
								cont++;
							if (m->getPunto(f - 1, c + 1)->getAbajo() == NULL)
								cont++;
							if (m->getPunto(f, c + 1)->getIzquierda() == NULL)
								cont++;

							if (cont == 1)
								return true;

						}

	return false;

}

bool CapturaPrimero::verificaAbajo(int f, int c, int j) {

	int cont = 0;

	if (f + 1 <= m->getFila() - 1 && f + 1 > f)
		if (m->getPunto(f, c) != NULL)
			if (c - 1 >= 0 && c - 1 < c)
				if (m->getPunto(f + 1, c - 1) != NULL)
					if (m->getPunto(f, c - 1) != NULL)
						if (m->getPunto(f + 1, c) != NULL) {

							if (m->getPunto(f, c)->getAbajo() == NULL)
								cont++;
							if (m->getPunto(f + 1, c)->getIzquierda() == NULL)
								cont++;
							if (m->getPunto(f + 1, c - 1)->getArriba() == NULL)
								cont++;
							if (m->getPunto(f, c - 1)->getDerecha() == NULL)
								cont++;

							if (cont == 1)
								return true;

						}

	return false;

}

bool CapturaPrimero::verificaIzquierda(int f, int c, int j) {

	int cont = 0;

	if (c - 1 >= 0 && c - 1 < c)
		if (m->getPunto(f, c) != NULL)
			if (f - 1 >= 0 && f - 1 < f)
				if (m->getPunto(f - 1, c - 1) != NULL)
					if (m->getPunto(f, c - 1) != NULL)
						if (m->getPunto(f - 1, c) != NULL) {

							if (m->getPunto(f, c)->getIzquierda() == NULL)
								cont++;
							if (m->getPunto(f, c - 1)->getArriba() == NULL)
								cont++;
							if (m->getPunto(f - 1, c - 1)->getDerecha() == NULL)
								cont++;
							if (m->getPunto(f - 1, c)->getAbajo() == NULL)
								cont++;

							if (cont == 1)
								return true;

						}

	return false;

}

bool CapturaPrimero::verificaDerecha(int f, int c, int j) {

	int cont = 0;

	if (c + 1 <= m->getColumna() - 1 && c + 1 > c)
		if (m->getPunto(f, c) != NULL)
			if (f + 1 <= m->getFila() - 1 && f + 1 > f)
				if (m->getPunto(f + 1, c + 1) != NULL)
					if (m->getPunto(f, c + 1) != NULL)
						if (m->getPunto(f + 1, c) != NULL) {

							if (m->getPunto(f, c)->getDerecha() == NULL)
								cont++;
							if (m->getPunto(f, c + 1)->getAbajo() == NULL)
								cont++;
							if (m->getPunto(f + 1, c + 1)->getIzquierda() == NULL)
								cont++;
							if (m->getPunto(f + 1, c)->getArriba() == NULL)
								cont++;

							if (cont == 1)
								return true;

						}

	return false;

}

//-------------------------------------------------------------------------------

bool CapturaPrimero::enlazaArriba(int f, int c, int j) {

	if (m->getPunto(f, c)->getArriba() == NULL) {

		cuadroArriba(f, c, j);

		m->getPunto(f, c)->setArriba(m->getPunto(f - 1, c));
		m->getPunto(f - 1, c)->setAbajo(m->getPunto(f, c));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f - 1, c), j, "arriba"));

		posicionarJugador(f, c, 0, 0, j);
		posicionarJugador(f, c, -1, 0, j);

		return true;

	}

	if (m->getPunto(f - 1, c)->getDerecha() == NULL) {

		cuadroDerecha(f - 1, c, j);

		m->getPunto(f - 1, c)->setDerecha(m->getPunto(f - 1, c + 1));
		m->getPunto(f - 1, c + 1)->setIzquierda(m->getPunto(f - 1, c));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f - 1, c), m->getPunto(f - 1, c + 1), j, "derecha"));

		posicionarJugador(f, c, -1, 0, j);
		posicionarJugador(f, c, -1, 1, j);

		return true;

	}


	if (m->getPunto(f - 1, c + 1)->getAbajo() == NULL) {

		cuadroAbajo(f - 1, c + 1, j);

		m->getPunto(f - 1, c + 1)->setAbajo(m->getPunto(f, c + 1));
		m->getPunto(f, c + 1)->setArriba(m->getPunto(f - 1, c + 1));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f - 1, c + 1), m->getPunto(f, c + 1), j, "abajo"));

		posicionarJugador(f, c, -1, 1, j);
		posicionarJugador(f, c, 0, 1, j);

		return true;

	}


	if (m->getPunto(f, c + 1)->getIzquierda() == NULL) {

		cuadroIzquierda(f, c + 1, j);

		m->getPunto(f, c + 1)->setIzquierda(m->getPunto(f, c));
		m->getPunto(f, c)->setDerecha(m->getPunto(f, c + 1));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c + 1), m->getPunto(f, c), j, "izquierda"));

		posicionarJugador(f, c, 0, 1, j);
		posicionarJugador(f, c, 0, 0, j);

		return true;

	}

	return true;

}

bool CapturaPrimero::enlazaAbajo(int f, int c, int j) {

	if (m->getPunto(f, c)->getAbajo() == NULL) {

		cuadroAbajo(f, c, j);

		m->getPunto(f, c)->setAbajo(m->getPunto(f + 1, c));
		m->getPunto(f + 1, c)->setArriba(m->getPunto(f, c));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f + 1, c), j, "abajo"));

		posicionarJugador(f, c, 0, 0, j);
		posicionarJugador(f, c, 1, 0, j);

		return true;

	}

	if (m->getPunto(f + 1, c)->getIzquierda() == NULL) {

		cuadroIzquierda(f + 1, c, j);

		m->getPunto(f + 1, c)->setIzquierda(m->getPunto(f + 1, c - 1));
		m->getPunto(f + 1, c - 1)->setDerecha(m->getPunto(f + 1, c));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f + 1, c), m->getPunto(f + 1, c - 1), j, "izquierda"));

		posicionarJugador(f, c, 1, 0, j);
		posicionarJugador(f, c, 1, -1, j);

		return true;

	}

	if (m->getPunto(f + 1, c - 1)->getArriba() == NULL) {

		cuadroArriba(f + 1, c - 1, j);

		m->getPunto(f + 1, c - 1)->setArriba(m->getPunto(f, c - 1));
		m->getPunto(f, c - 1)->setAbajo(m->getPunto(f + 1, c - 1));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f + 1, c - 1), m->getPunto(f, c - 1), j, "arriba"));

		posicionarJugador(f, c, 1, -1, j);
		posicionarJugador(f, c, 0, -1, j);

		return true;

	}

	if (m->getPunto(f, c - 1)->getDerecha() == NULL) {

		cuadroDerecha(f, c - 1, j);

		m->getPunto(f, c - 1)->setDerecha(m->getPunto(f, c));
		m->getPunto(f, c)->setIzquierda(m->getPunto(f, c - 1));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c - 1), m->getPunto(f, c), j, "derecha"));

		posicionarJugador(f, c, 0, -1, j);
		posicionarJugador(f, c, 0, 0, j);

		return true;

	}

	return true;

}

bool CapturaPrimero::enlazaIzquierda(int f, int c, int j) {

	if (m->getPunto(f, c)->getIzquierda() == NULL) {

		cuadroIzquierda(f, c, j);

		m->getPunto(f, c)->setIzquierda(m->getPunto(f, c - 1));
		m->getPunto(f, c - 1)->setDerecha(m->getPunto(f, c));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c - 1), j, "izquierda"));

		posicionarJugador(f, c, 0, 0, j);
		posicionarJugador(f, c, 0, -1, j);

		return true;

	}

	if (m->getPunto(f, c - 1)->getArriba() == NULL) {

		cuadroArriba(f, c - 1, j);

		m->getPunto(f, c - 1)->setArriba(m->getPunto(f - 1, c - 1));
		m->getPunto(f - 1, c - 1)->setAbajo(m->getPunto(f, c - 1));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c - 1), m->getPunto(f - 1, c - 1), j, "arriba"));

		posicionarJugador(f, c, 0, -1, j);
		posicionarJugador(f, c, -1, -1, j);

		return true;

	}

	if (m->getPunto(f - 1, c - 1)->getDerecha() == NULL) {

		cuadroDerecha(f - 1, c - 1, j);

		m->getPunto(f - 1, c - 1)->setDerecha(m->getPunto(f - 1, c));
		m->getPunto(f - 1, c)->setIzquierda(m->getPunto(f - 1, c - 1));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f - 1, c - 1), m->getPunto(f - 1, c), j, "derecha"));

		posicionarJugador(f, c, -1, -1, j);
		posicionarJugador(f, c, -1, 0, j);

		return true;

	}

	if (m->getPunto(f - 1, c)->getAbajo() == NULL) {

		cuadroAbajo(f - 1, c, j);

		m->getPunto(f - 1, c)->setAbajo(m->getPunto(f, c));
		m->getPunto(f, c)->setArriba(m->getPunto(f - 1, c));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f - 1, c), m->getPunto(f, c), j, "abajo"));

		posicionarJugador(f, c, -1, 0, j);
		posicionarJugador(f, c, 0, 0, j);

		return true;

	}

	return true;

}
	
bool CapturaPrimero::enlazaDerecha(int f, int c, int j) {

	if (m->getPunto(f, c)->getDerecha() == NULL) {

		cuadroDerecha(f, c, j);

		m->getPunto(f, c)->setDerecha(m->getPunto(f, c + 1));
		m->getPunto(f, c + 1)->setIzquierda(m->getPunto(f, c));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c), m->getPunto(f, c + 1), j, "derecha"));

		posicionarJugador(f, c, 0, 0, j);
		posicionarJugador(f, c, 0, 1, j);

		return true;

	}

	if (m->getPunto(f, c + 1)->getAbajo() == NULL) {

		cuadroAbajo(f, c + 1, j);

		m->getPunto(f, c + 1)->setAbajo(m->getPunto(f + 1, c + 1));
		m->getPunto(f + 1, c + 1)->setArriba(m->getPunto(f, c + 1));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f, c + 1), m->getPunto(f + 1, c + 1), j, "abajo"));

		posicionarJugador(f, c, 0, 1, j);
		posicionarJugador(f, c, 1, 1, j);

		return true;

	}

	if (m->getPunto(f + 1, c + 1)->getIzquierda() == NULL) {

		cuadroIzquierda(f + 1, c + 1, j);

		m->getPunto(f + 1, c + 1)->setIzquierda(m->getPunto(f + 1, c));
		m->getPunto(f + 1, c)->setDerecha(m->getPunto(f + 1, c + 1));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f + 1, c + 1), m->getPunto(f + 1, c), j, "izquierda"));

		posicionarJugador(f, c, 1, 1, j);
		posicionarJugador(f, c, 1, 0, j);

		return true;

	}

	if (m->getPunto(f + 1, c)->getArriba() == NULL) {

		cuadroArriba(f + 1, c, j);

		m->getPunto(f + 1, c)->setArriba(m->getPunto(f, c));
		m->getPunto(f, c)->setAbajo(m->getPunto(f + 1, c));

		m->getLineas()->ingresaDeUltimo(new Linea(m->getPunto(f + 1, c), m->getPunto(f, c), j, "arriba"));

		posicionarJugador(f, c, 1, 0, j);
		posicionarJugador(f, c, 0, 0, j);

		return true;


	}

	return true;

}

//-------------------------------------------------------------------------------