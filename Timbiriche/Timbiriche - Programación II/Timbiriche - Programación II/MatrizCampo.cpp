#include "MatrizCampo.h"
#include <string>
#include "ColorConsola.h"

MatrizCampo::MatrizCampo(int f, int c) : Matriz(f, c) {

	m = new Punto * *[fila];

	for (int i = 0; i < fila; i++)
		m[i] = new Punto * [columna];
	
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			m[i][j] = new Punto();

	campos = new Lista<string>;

	lineas = new Lista<Linea>;
	cuadros = new Lista<Cuadro>;

}

MatrizCampo::~MatrizCampo() {

	for (int i = 0; i < fila; i++)
			delete m[i];

	delete[] m;

	delete lineas, cuadros;

}

Punto* MatrizCampo::getPunto(int f, int c) {

	return m[f][c];

}

void MatrizCampo::setPunto(int f, int c, Punto* p) {

	m[f][c] = p;

}

void MatrizCampo::limpaMatriz() {

	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			m[i][j] = NULL;

}

void MatrizCampo::imprimeMatrizCampo() {

	system("mode con: cols=500 lines=150");

	for (int i = 0; i < fila; i++) {

		if (i != 0) {

			for (int j = 0; j < columna; j++) { // rayas verticales

				if (m[i][j] != NULL) {

					if (m[i][j]->getArriba() != NULL) {

						if (getLinea(m[i][j], m[i][j]->getArriba())->getJugador() == 1)
							cout << verde << "|";
						else
							cout << rojo << "|";

						if (getCuadro(m[i][j], m[i - 1][j], m[i][j]->getDerecha(), m[i - 1][j]->getDerecha()) != NULL)
							cout << " " << azul << getCuadro(m[i][j], m[i - 1][j], m[i][j]->getDerecha(), m[i - 1][j]->getDerecha())->getJugador() << " ";
						else
							cout << "   ";

					}
					else {

						cout << "    ";

					}

				}
				else {

					cout << "    ";

				}

			}

			cout << endl;

		}

		for (int j = 0; j < columna; j++) { // rayas horizontales

			if (m[i][j] != NULL) {

				cout << blanco << "*";

				if (m[i][j]->getDerecha() != NULL) {

					if (getLinea(m[i][j], m[i][j]->getDerecha())->getJugador() == 1)
						cout << verde << "---";
					else
						cout << rojo << "---";

				}
				else {

					cout << "   ";

				}

			}
			else {

				cout << "    ";

			}

		}

		cout << endl;

	}

}

void MatrizCampo::actualizaColumnas() {

	int col = 0;
	bool dentro = false;

	for (int i = 0; i < columna; i++) {

		for (int j = 0; j < fila && dentro == false; j++) {

			if (m[j][i] != NULL) {

				col++;
				dentro = true;

			}

		}

		dentro = false;

	}

	columna = col;

}

void MatrizCampo::actualizaFilas() {

	int fil = 0;
	bool dentro = false;

	for (int i = 0; i < fila; i++) {

		for (int j = 0; j < columna && dentro == false; j++) {

			if (m[i][j] != NULL) {

				fil++;
				dentro = true;

			}

		}

		dentro = false;

	}

	fila = fil;

}

Lista<Linea>* MatrizCampo::getLineas() const { return lineas; }

Linea* MatrizCampo::getLinea(Punto* p1, Punto* p2) {

	Iterador<Linea>* i = lineas->obtenerIterador();
	Linea* aux = NULL;

	while (i->masElementos()) {

		aux = i->proxElemento();

		if (aux->conformanLinea(p1, p2)) {

			delete i;
			return aux;

		}
			
	}

	delete i;
	return aux;

}

Lista<string>* MatrizCampo::getCampos() { return campos; }
void MatrizCampo::setCampos(Lista<string>* campos) { this->campos = campos; }

Lista<Cuadro>* MatrizCampo::getCuadros() const { return cuadros; }

Cuadro* MatrizCampo::getCuadro(Punto* ar, Punto* ab, Punto* iz, Punto* de) const {

	Iterador<Cuadro>* i = cuadros->obtenerIterador();
	Cuadro* aux = NULL;

	while (i->masElementos()) {

		aux = i->proxElemento();

		if (aux->conformanCuadro(ar, ab, iz, de)){
		
			delete i;
			return aux;

		}

	}

	delete i;
	return NULL;

}

int  MatrizCampo::cuadrosJugador(int j) {

	int cont = 0;
	Iterador<Cuadro>* i = cuadros->obtenerIterador();

	while (i->masElementos()) {

		if (i->proxElemento()->getJugador() == j)
			cont++;

	}

	delete i;
	return cont;

}

void MatrizCampo::restablecerPuntos() {

	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			if (m[i][j] != NULL)
				m[i][j] = new Punto(i, j);

}

void  MatrizCampo::ganador() {

	cout << verde << "[JUGADOR 1]Cuadros capturados: " << cuadrosJugador(1) << endl;
	cout << rojo << "[JUGADOR 2]Cuadros capturados: " << cuadrosJugador(2) << endl;
	cout << endl;

	if (cuadrosJugador(1) > cuadrosJugador(2))
		cout << verde << "[GANADOR JUGADOR 1] - El jugador 1 capturo mas cuadros" << endl; 
	else if (cuadrosJugador(1) == cuadrosJugador(2))
		cout << azul << "[EMPATE] - Ambos jugadores capturaron la misma cantidad de cuadros" << endl;
	else
		cout << rojo << "[GANADOR JUGADOR 2] - El jugador 2 capturo mas cuadros" << endl;

}