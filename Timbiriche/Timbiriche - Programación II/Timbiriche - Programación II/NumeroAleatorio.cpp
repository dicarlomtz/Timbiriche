#include "NumeroAleatorio.h"

double NumeroAleatorio::numeroAleatorio(int lim1, int lim2) { // limite de numero aleatorio

	int x = 0;

	srand(time(NULL));

	x = lim1 + rand() % lim2; //aleatorio de lim1 a lim2

	return x; 

}