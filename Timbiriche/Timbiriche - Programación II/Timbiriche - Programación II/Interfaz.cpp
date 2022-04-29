#include "Interfaz.h"

void Interfaz::bienvenida() {

	imprimeCadena("\t|----------------------------------------|\n");
	imprimeCadena("\t|BIENVENDIO AL MENU DE LA EMPRESA DIDOTTS|\n");
	imprimeCadena("\t|----------------------------------------|\n\n");

}

int Interfaz::menu() {

	int op;

	while (true) {

		imprimeCadena("\tIngrese una opcion...\n\n");

		try {

			op = leeEntero("\t[1]-Registrarme como jugador\n\t[2]-Ver codigo adquirido\n\t[3]-Reproducir partida\n\t[4]-Jugar una partida\n\t[5]-Cambiar de dia\n\t[6]-Salir\n\n\tOpcion");

			limpiaPantalla();

			if (op < 1 || op > 6)
				throw new OutOfRangeException(1, 6);

			return op;

		}
		catch (Exception* e) {

			imprimeCadena(e->toString() + "\n");

		}

	}

}

void Interfaz::despedida() {

	imprimeCadena("\t|------------------------------------------|\n");
	imprimeCadena("\t|SE AGRADECE EL USO DEL PROGRAMA DE DIDOTTS|\n");
	imprimeCadena("\t|------------------------------------------|\n\n");

	system("pause");
	limpiaPantalla();

}

//---------------------//

void Interfaz::registrarJugador(Empresa* m) {

	int id, op;
	string nombre;

	imprimeCadena("Porfavor ingrese los datos que se le solicitan...\n\n");

	try {

		id = leeEntero("-Ingrese su identificacion");
		limpiaPantalla();

		if (m->jugadorRepetido(devuelveCadena(id)))
			throw new ExistPlayerException;

		imprimeCadena("-Ingrese su nombre: ");
		nombre = leeCadena();

		limpiaPantalla();

		imprimeCadena("-Para proceder con su regristro debe pagar 500 colones-\n");
		imprimeCadena("Para realizar el pago se hace un enlaze entre su ID y cuenta bancaria\n\n");
		imprimeCadena("Desea proceder con su pago?\n\n");
		op = leeEntero("[1]Proceder con el pago\n[2]Salir sin registrar\n\n-Opcion");

		limpiaPantalla();

		if (op != 1 && op != 2)
			throw new OutOfRangeException(1, 2);

		if (op == 1) {

			Jugador* ju = new Jugador(devuelveCadena(id), nombre, m);
			imprimeCadena("-Registro realizado con exito-\n\n");
			imprimeCadena(ju->toString());

		}

	}
	catch (Exception* e) {

		imprimeCadena(e->toString() + "\n");

	}

	system("pause");
	limpiaPantalla();

}

void Interfaz::verCodigoObtenido(Empresa* m) {

	int id;

	id = leeEntero("-Ingrese su identificacion");

	limpiaPantalla();

	try {

		if (!m->jugadorRepetido(devuelveCadena(id)))
			throw new NoExistPlayerException;


		imprimeCadena(m->getJugador(devuelveCadena(id))->toString());

	}
	catch (Exception* e) {

		imprimeCadena(e->toString() + "\n");

	}

	system("pause");
	limpiaPantalla();

}

void Interfaz::verPartida(Empresa* m) {

	int id;
	int pos;

	id = leeEntero("-Ingrese su identificacion");
	limpiaPantalla();

	try {

		if (!m->jugadorRepetido(devuelveCadena(id)))
			throw new NoExistPlayerException;

		if (m->getPartidas()->canNodos() != 0) {

			while (true) {

				try {

					pos = leeEntero(m->imprimePartidas() + "\n\nNumero de partida");
					limpiaPantalla();

					if (pos < 1 || pos > m->getPartidas()->canNodos())
						throw new OutOfRangeException(1, m->getPartidas()->canNodos());

					m->getPartida(pos)->replicaPartida();
					break;

				}
				catch (Exception* e) {

					imprimeCadena(e->toString() + "\n");

				}

			}

		}
		else {

			imprimeCadena("-No hay partidas registradas-\n\n");

		}


	}
	catch (Exception* e) {

		imprimeCadena(e->toString() + "\n");

	}

	system("pause");
	limpiaPantalla();

}

//--------------------//

void Interfaz::cambiarDia(Empresa* m) {

	int op;
	string clave;

	imprimeCadena("-Ingrese la clave de la empresa: ");
	getline(cin, clave);
	limpiaPantalla();

	if (clave == m->getClave()) {

		try {

			op = leeEntero("Desea cambiar al dia siguiente?\n\n[1]Si\n[2]No\n\nOpcion");
			limpiaPantalla();

			if (op < 1 || op > 2)
				throw new OutOfRangeException(1, 2);

			if (op == 1) {

				m->generaCodigo();
				imprimeCadena("-Nuevo codigo " + m->getCodigo() + " aniadido con exito-\n\n");

			}

		}
		catch (Exception* e) {

			imprimeCadena(e->toString() + "\n");

		}

	}
	else {

		imprimeCadena("-Clave invalida-\n\n");

	}

	system("pause");
	limpiaPantalla();

}

//------------------//

bool Interfaz::ingresarCodigo(Empresa* m) {

	int codigo;

	codigo = leeEntero("-Ingrese el codigo que se le ha proveido");
	limpiaPantalla();

	if (m->getCodigo() != devuelveCadena(codigo)) {

		imprimeCadena("-Codigo invalido-\n\n");
		return false;

	}

	imprimeCadena("-Codigo valido-\n\n");
	return true;

}

int Interfaz::elegirModoJuego() {

	int op;

	while (true) {

		try {

			imprimeCadena("Escoga una opcion...\n\n");
			op = leeEntero("[1]Jugador Vs Jugador\n[2]Jugador Vs Maquina\n\nOpcion");
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

MatrizCampo* Interfaz::obtenerCampoJuego() {

	int can, op;
	MatrizCampo* m = NULL;

	while (true) {

		try {

			can = leeEntero("Ingrese la cantidad de campos que desea usar");
			limpiaPantalla();

			if (can < 1 || can > 20)
				throw new OutOfRangeException(1, 20);

			CampoJuego* campo = new CampoJuego(can);

			for (int i = 0; i < can; i++) {

				try {

					op = leeEntero("-Eliga una opcion-\n\n[1]Campo seis puntos\n[2]Campo nueve puntos\n[3]Campo quince puntos\n\nOpcion");
					limpiaPantalla();

					if (op < 1 || op > 3)
						throw new OutOfRangeException(1, 3);

					switch (op) {

					case 1: campo->ingresaCampo(new CampoSeisPuntos); break;
					case 2: campo->ingresaCampo(new CampoNuevePuntos); break;
					case 3: campo->ingresaCampo(new CampoQuincePuntos); break;

					}


				}
				catch (Exception* e) {

					imprimeCadena(e->toString() + "\n");
					i--;

				}

			}

			ProcesaCompuesto pros(campo->getContenedor());
			m = pros.getMatriz();
			return m;

		}
		catch (Exception* e) {

			imprimeCadena(e->toString() + "\n");

		}

	}

	return m;

}

Jugador* Interfaz::obtenerJugador1(Empresa* m) {

	int id;

	id = leeEntero("-Ingrese su identificacion");
	limpiaPantalla();

	try {

		if (!m->jugadorRepetido(devuelveCadena(id)))
			throw new NoExistPlayerException;

		m->getJugador(devuelveCadena(id))->setNumJugador(1);
		return m->getJugador(devuelveCadena(id));

	}
	catch (Exception* e) {

		imprimeCadena(e->toString() + "\n");

	}

	return NULL;

}

Jugador* Interfaz::obtenerJugador2() {

	string nombre;
	Jugador* j = NULL;

	if (elegirModoJuego() == 1) {

		imprimeCadena("Ingrese el nombre del jugador 2: ");
		nombre = leeCadena();

	}
	else {

		nombre = "Maquina";

	}

	limpiaPantalla();
	j = new Jugador("000", nombre, NULL);
	j->setNumJugador(2);

	return j;

}