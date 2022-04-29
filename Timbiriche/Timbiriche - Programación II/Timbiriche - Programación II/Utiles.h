#ifndef UTILES_H
#define UTILES_H
#include "Excepcion.h"
#include "ColorConsola.h"
#include <ctime>
#include <cstdlib>
using namespace std;

void imprimeCadena(string);
void limpiaPantalla();
void esperaEnter();
string leeCadena();
int leeEntero(string);
double leeFlotante(string);
void convierteMayuscula(string&);
string devuelveCadena(double);
double devuelveDouble(string);

#endif