#include "Partida.h"

Partida::Partida(Lista<Linea>* lineas, Lista<string>* campos, string j1, string j2) :
	lineas(lineas), campos(campos), jugador1(j1), jugador2(j2) {

	campo = new CampoJuego(campos->canNodos());
	cuadros = new Lista<Cuadro>;
	m = NULL;
	procesaMatrizCampo();

}

Partida::~Partida() {

	delete campos;
	delete campo;
	delete cuadros;
	delete m;
	delete lineas;

}

Lista<string>* Partida::getCampos() const { return campos; }
void Partida::setCampos(Lista<string>* campos) { this->campos = campos; }

Lista<Linea>* Partida::getLineas() const { return lineas; }
void Partida::setLineas(Lista<Linea>* lineas) { this->lineas = lineas; }

Lista<Cuadro>* Partida::getCuadros() const { return cuadros; }
void Partida::setCuadros(Lista<Cuadro>* cuadros) { this->cuadros = cuadros; }

CampoJuego* Partida::getCampo() const { return campo; }
void Partida::setCampo(CampoJuego* campo) { this->campo = campo; }

MatrizCampo* Partida::getMatrizCampo() const { return m; }
void Partida::setMatrizCampo(MatrizCampo* m) { this->m = m; }

string Partida::getJugador1() const { return jugador1; }
void Partida::setJugador1(string jugador1) { this->jugador1 = jugador1; }

string Partida::getJugador2() const { return jugador2; }
void Partida::setJugador2(string jugador2) { this->jugador2 = jugador2; }

void Partida::procesaMatrizCampo() {

	Iterador<string>* i = campos->obtenerIterador();
	string aux = "";

	while (i->masElementos()) {

		aux = *i->proxElemento();

		if (aux == "SeisPuntos")
			campo->ingresaCampo(new CampoSeisPuntos());
		else if (aux == "QuincePuntos")
			campo->ingresaCampo(new CampoQuincePuntos());
		else
			campo->ingresaCampo(new CampoNuevePuntos());


	}

	delete i;

	ProcesaCompuesto pros(campo->getContenedor());

	m = pros.getMatriz();

}

void Partida::replicaPartida() {

	ColocaLineasCuadros clc;

	Iterador<Linea>* i = lineas->obtenerIterador();
	Linea* aux = NULL;

	m->imprimeMatrizCampo();
	Sleep(5000);

	while (i->masElementos()) {

		Sleep(2500);

		aux = i->proxElemento();

		if (aux->getDireP1() == "arriba")
			clc.enlazaArriba(aux->getP1()->getFila(), aux->getP1()->getColumna(), aux->getJugador(), m);
		if(aux->getDireP1() == "abajo")
			clc.enlazaAbajo(aux->getP1()->getFila(), aux->getP1()->getColumna(), aux->getJugador(), m);
		if(aux->getDireP1() == "izquierda")
			clc.enlazaIzquierda(aux->getP1()->getFila(), aux->getP1()->getColumna(), aux->getJugador(), m);
		if(aux->getDireP1() == "derecha")
			clc.enlazaDerecha(aux->getP1()->getFila(), aux->getP1()->getColumna(), aux->getJugador(), m);
			
		m->imprimeMatrizCampo();

	}

	m->ganador();
	m->restablecerPuntos();

	delete i;

}

ostream& operator << (ostream& out, const Partida& p) {

	return out << p.jugador1 << " Vs " << p.jugador2 << endl;

}

void Partida::guardaPartida(ofstream& out) {

	out << jugador1 << DELIMITA_REGISTRO;
	out << jugador2 << DELIMITA_REGISTRO;

	out << campos->canNodos() << DELIMITA_REGISTRO;

	Iterador<string>* i = campos->obtenerIterador();

	while (i->masElementos()) {

		out << *i->proxElemento() << DELIMITA_REGISTRO;

	}

	out << lineas->canNodos() << DELIMITA_REGISTRO;

	Iterador<Linea>* j = lineas->obtenerIterador();

	while (j->masElementos()) {

		j->proxElemento()->guardaLinea(out);

	}

	delete i, j;

}

void Partida::leePartida(ifstream& in) {

	string j1, j2;

	string _campos;
	int canCampos;
	string _canCampos;
	Lista<string>* listaCampos = new Lista<string>;

	Linea _linea;
	int canLineas;
	string _canLineas;
	Lista<Linea>* _lineas = new Lista<Linea>;

	getline(in, j1);
	getline(in, j2);

	this->jugador1 = j1;
	this->jugador2 = j2;

	getline(in, _canCampos);
	canCampos = atoi(_canCampos.c_str());

	while (canCampos != 0) {

		getline(in, _campos);
		listaCampos->ingresaDeUltimo(new string(_campos));

		canCampos--;

	}

	this->campos = listaCampos;

	getline(in, _canLineas);
	canLineas = atoi(_canLineas.c_str());

	while (canLineas != 0) {

		_linea.leeLinea(in);
		_lineas->ingresaDeUltimo(new Linea(_linea.getP1(), _linea.getP2(), _linea.getJugador(), _linea.getDireP1()));

		canLineas--;

	}

	this->lineas = _lineas;

}