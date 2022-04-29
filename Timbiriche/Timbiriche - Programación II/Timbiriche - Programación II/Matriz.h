#pragma once
#include "Contenedor.h"

class Matriz : public Contenedor {

protected:

	int fila;
	int columna;

public:

	Matriz(int, int);
	virtual ~Matriz();

	int getFila() const;
	int getColumna() const;

};