#include "Matriz.h"

Matriz::Matriz(int f, int c) : 
	fila(f), columna(c) {}

Matriz::~Matriz() {}

int Matriz::getFila() const { return fila; }
int Matriz::getColumna() const { return columna; }