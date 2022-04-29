#pragma once
#include "InterfazPartida.h"

class Control {

private:

	Empresa* m;

public:

	Control();
	virtual ~Control();
	void controlPrincipal();

	void control1();
	void control2();
	void control3();
	void control4();
	void control5();

};