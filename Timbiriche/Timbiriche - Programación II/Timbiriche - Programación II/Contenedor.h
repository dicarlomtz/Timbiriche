#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ColorDlg.h>
using namespace std;

class Contenedor {

public:

	virtual string tipo() { return typeid(*this).name(); }

};