#include "Empresa.h"

Empresa::Empresa(string nombre) : 
	nombre(nombre){

	jugadores = new Lista<Jugador>;
	partidas = new Lista<Partida>;
	clave = "12345678";
	cargarPartidas();
	generaCodigo();
}

Empresa::~Empresa() {

	guardarPartidas();
	delete jugadores;
	delete partidas;

}

void Empresa::attach(Jugador* j) {

	jugadores->ingresaDePrimero(j);

}

string Empresa::getCodigo() const { return codigo; }

void Empresa::generaCodigo() {

	jugadores->limpiaLista();

	NumeroAleatorio num;

	string cod;
	cod = devuelveCadena(num.numeroAleatorio(100000, 999999));
	
	codigo = cod;

}

string Empresa::getClave() const { return clave; }
void Empresa::setClave(string clave) { this->clave = clave; }

bool Empresa::jugadorRepetido(string id) {

	Iterador<Jugador>* i = jugadores->obtenerIterador();

	while (i->masElementos()) {

		if (i->proxElemento()->getCedula() == id) {

			delete i;
			return true;
		}

	}

	delete i;
	return false;

}

bool Empresa::otroJugador(string id) {

	Iterador<Jugador>* i = jugadores->obtenerIterador();

	while (i->masElementos()) {

		if (i->proxElemento()->getCedula() != id) {

			delete i;
			return true;

		}

	}

	delete i;
	return false;
}

Jugador* Empresa::getJugador(string id) {

	Iterador<Jugador>* i = jugadores->obtenerIterador();
	Jugador* aux = NULL;

	while (i->masElementos()) {

		aux = i->proxElemento();

		if (aux->getCedula() == id)
			return aux;

	}

	delete i;
	return aux;

}

void Empresa::imprimeJugadores() {

	cout << jugadores->toString() << endl;

}

void Empresa::guardarPartidas() {

	ofstream out("../Partidas.txt", ios::out);

	Iterador<Partida>* i = partidas->obtenerIterador();

	while (i->masElementos()) {

		i->proxElemento()->guardaPartida(out);

	}

	out.close();
	delete i;

}

void Empresa::cargarPartidas() {

	Partida parAux;
	Partida* partida = NULL;

	ifstream in("../Partidas.txt", ios::in);

	partidas->limpiaLista();

	if (!in.fail()) {

		parAux.leePartida(in);

		while (in.good()) {

			partida = new Partida(parAux.getLineas(), parAux.getCampos(), parAux.getJugador1(), parAux.getJugador2());
			agregarPartidas(partida);
			parAux.leePartida(in);

		}

		in.clear();
		in.close();

	}

}

void Empresa::agregarPartidas(Partida* p) {

	partidas->ingresaDePrimero(p);

}

Lista<Partida>* Empresa::getPartidas() const { return partidas; }

void Empresa::setPartidas(Lista<Partida>* partidas) { this->partidas = partidas; }

string Empresa::imprimePartidas() { 

	stringstream s;
	
	s << "Jugador 1 Vs Jugador 2" << endl << endl;

	s << partidas->toString() << endl;

	return s.str();

}

Partida* Empresa::getPartida(int pos) {

	if (pos <= partidas->canNodos())
		return partidas->obtenerElemento(pos);

	return NULL;

}