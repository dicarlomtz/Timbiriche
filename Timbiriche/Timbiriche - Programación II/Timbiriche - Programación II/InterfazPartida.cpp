#include "InterfazPartida.h"

MatrizCampo* InterfazPartida::m = NULL;
Jugador* InterfazPartida::v[2] = { NULL, NULL };

void InterfazPartida::inicializarEstrategia() {

	imprimeCadena("-Seleccionen sus jugadas de inicio-\n\n");
	imprimeCadena("Jugador 1\n\n");
	v[0]->setJugada(escogerEstrategia());
	imprimeCadena("Jugador 2\n\n");
	v[1]->setJugada(escogerEstrategia());

}

void InterfazPartida::juega(Empresa* em) {

	if (prepararPartida(em)) {

		int i = 0;
		int op = 0;
		Jugada* aleatoria = new Aleatorio(m);

		imprimeCadena("[Jugador 1]-" + v[0]->getNombre() + " Verde\n");
		imprimeCadena("[Jugador 2]-" + v[1]->getNombre() + " Rojo\n\n");
		inicializarEstrategia();

		while (v[i]->getJugada()->masJugadas()) {

			imprimeCadena("Turno de " + v[i]->getNombre() + " Jugador ");
			cout << i + 1;
			imprimeCadena("\n\n");

			if (v[i]->getNombre() != "Maquina") {

				op = tomarDesicion();

				if (op == 2)
					v[i]->setJugada(escogerEstrategia());

			}

			imprimeCadena("\n\nRealizando jugada...");
			Sleep(500);

			if (v[i]->jugar()) {

				imprimeCadena("-Jugada realizada con exito\n\n");

			}
			else {

				aleatoria->realizarJugada(v[i]->getNumJugador());
				imprimeCadena("-La estrategia era peligrosa o no se podia seguir-\n");
				imprimeCadena("-Se realizo un juego aleatorio-\n\n");

			}

			Sleep(1500);
			m->imprimeMatrizCampo();
			Sleep(5000);
			cout << endl << endl;
			limpiaPantalla();

			if (v[i]->getJugada()->getCuadroCapturado() == false) {

				i = (i == 0) ? 1 : 0;

			}

		}

		m->ganador();
		system("pause");
		limpiaPantalla();
		em->getPartidas()->ingresaDePrimero(guardarPartida());
		delete aleatoria;
		delete v[1];
	}

}

bool InterfazPartida::prepararPartida(Empresa* em) {

	v[0] = Interfaz::obtenerJugador1(em);

	if (v[0] != NULL) {

		if (Interfaz::ingresarCodigo(em)) {

			v[1] = Interfaz::obtenerJugador2();

			m = Interfaz::obtenerCampoJuego();

			return true;

		}

	}

	return false;

}

int InterfazPartida::tomarDesicion() {

	int op;

	while (true) {


		try {

			op = leeEntero("-Escoga una opcion\n\n[1]Realizar jugada\n[2]Cambiar estrategia\n\nOpcion");
			limpiaPantalla();

			if (op < 1 || op > 2)
				throw new OutOfRangeException(1, 2);

			return op;

		}
		catch (Exception* e) {

			imprimeCadena(e->toString() + "\n");

		}

	}

}

Jugada* InterfazPartida::escogerEstrategia() {

	int op;

	while (true) {

		try {

			op = leeEntero("-Escoga una jugada-\n\n[1]Aleatorio\n[2]Central\n[3]Cercano\n[4]Islas\n[5]Periferico\n\nOpcion");
			limpiaPantalla();

			if (op < 1 || op > 5)
				throw OutOfRangeException(1, 5);

			switch (op) {

			case 1: return new Aleatorio(m); break;
			case 2: return new Central(m); break;
			case 3: return new Cercano(m); break;
			case 4: return new Islas(m); break;
			case 5: return new Periferico(m); break;

			}

			return NULL;

		}
		catch (Exception* e) {

			imprimeCadena(e->toString() + "\n");

		}

	}


}

Partida* InterfazPartida::guardarPartida() {

	Lista<Linea>* lineas = new Lista<Linea>;
	Iterador<Linea>* i = m->getLineas()->obtenerIterador();

	while (i->masElementos()) {

		lineas->ingresaDeUltimo(new Linea(*i->proxElemento()));

	}

	return new Partida(lineas, m->getCampos(), v[0]->getNombre(), v[1]->getNombre());

}