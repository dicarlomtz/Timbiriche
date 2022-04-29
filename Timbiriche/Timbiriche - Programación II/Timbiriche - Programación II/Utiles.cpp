#include "Utiles.h"

void imprimeCadena(string cadena) {

	cout << blanco << cadena;

}

string leeCadena() {

	string cadena;

	getline(cin, cadena);

	return cadena;

}

void esperaEnter() {

	imprimeCadena("\n\n[PRESIONE ENTER]");
	cin.get();

}

int leeEntero(string texto) {

	int n;

	while (true) {

		try {

			imprimeCadena(texto + ": ");

			if (cin >> n) {

				cin.clear();
				cin.ignore(1024, '\n');
				return n;

			}
			else {

				limpiaPantalla();
				cin.clear();
				cin.ignore(1024, '\n');
				throw new TypeOfDataException;

			}

		}
		catch (Exception* e) {

			imprimeCadena(e->toString() + "\n\n");

		}

	}

}

double leeFlotante(string texto) {

	float n;

	while (true) {

		try {

			imprimeCadena(texto + ": ");

			if (cin >> n) {

				cin.clear();
				cin.ignore(1024, '\n');
				return n;

			}
			else {

				limpiaPantalla();
				cin.clear();
				cin.ignore(1024, '\n');
				throw new TypeOfDataException;

			}

		}
		catch (TypeOfDataException* e) {

			imprimeCadena(e->toString() + "\n\n");

		}

	}

}

void limpiaPantalla() {

	system("cls");

}

string devuelveCadena(double x) {

	stringstream d;

	d << x;

	return d.str();

}

void convierteMayuscula(string& cadena) {

	for (int i = 0; i < cadena.length(); i++) {

		cadena[i] = toupper(cadena[i]);

	}

}

double devuelveDouble(string cadena) {

	stringstream r(cadena);

	double d;

	r >> d;

	return d;

}