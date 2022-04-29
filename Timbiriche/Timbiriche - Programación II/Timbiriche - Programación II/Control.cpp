#include "Control.h"

Control::Control() {

	Interfaz::bienvenida();
	m = new Empresa("DEDOTTS");

}

Control::~Control() {

	Interfaz::despedida();
	delete m;

}

void Control::controlPrincipal() {

	int op;

	do {

		op = Interfaz::menu();

		switch (op) {

		case 1: control1(); break;
		case 2: control2(); break;
		case 3: control3(); break;
		case 4: control4(); break;
		case 5: control5(); break;

		}

	} while (op != 6);

}

void Control::control1() {

	
	Interfaz::registrarJugador(m);

}

void Control::control2() {

	Interfaz::verCodigoObtenido(m);

}

void Control::control3() {

	Interfaz::verPartida(m);

}

void Control::control4() {

	InterfazPartida::juega(m);

}

void Control::control5() {

	Interfaz::cambiarDia(m);

}