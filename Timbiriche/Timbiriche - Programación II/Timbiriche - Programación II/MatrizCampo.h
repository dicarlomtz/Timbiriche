#pragma once
#include "Linea.h"
#include "Matriz.h"
#include "Lista.h"
#include "Cuadro.h"

class MatrizCampo : public Matriz {

private:

	Punto*** m;
	Lista<Linea>* lineas;
	Lista<Cuadro>* cuadros;
	Lista<string>* campos;

public:

	MatrizCampo(int, int);
	virtual ~MatrizCampo();
	Punto* getPunto(int, int);
	void setPunto(int, int, Punto*);
	void limpaMatriz();
	void actualizaColumnas();
	void actualizaFilas();
	void imprimeMatrizCampo();
	Lista<Linea>* getLineas() const;
	Linea* getLinea(Punto*, Punto*);
	Lista<Cuadro>* getCuadros() const;
	Cuadro* getCuadro(Punto*, Punto*, Punto*, Punto*) const;
	int cuadrosJugador(int);
	Lista<string>* getCampos();
	void setCampos(Lista<string>*);
	void restablecerPuntos();
	void ganador();
	
};