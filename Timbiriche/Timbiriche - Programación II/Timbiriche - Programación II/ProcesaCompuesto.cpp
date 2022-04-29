#include "ProcesaCompuesto.h"

ProcesaCompuesto::ProcesaCompuesto(Contenedor* c) {

	v = dynamic_cast<ContenedorV*>(c);
	m = new MatrizCampo(5, 70);
	m->limpaMatriz();
	this->pasarInfoVecAMat();
	m->actualizaColumnas();
	m->actualizaFilas();

}

ProcesaCompuesto::~ProcesaCompuesto() {}

void ProcesaCompuesto::pasarInfoVecAMat() {

	int columna = 0;

	MatrizCampo* mc = NULL;

	for (int k = 0; k < v->getCan(); k++) { // Recorre los campos

		mc = dynamic_cast<MatrizCampo*>(v->getPos(k)->getContenedor());

		m->getCampos()->ingresaDeUltimo(new string(v->getPos(k)->getCodigo()));

		for (int i = 0; i < mc->getColumna(); i++) { //Columnas de un campo en especifico

			for (int j = 0; j < mc->getFila(); j++) { // filas de un campo en especifico

				m->setPunto(j, columna, new Punto(j, columna)); // Las filas del campo grande van a ser las mismas que las de un campo en especifico
															
			}

			columna++; // Sus columnas si cambian conforme pasa de campos, por lo que columna++ se encarga de posicionarnos de manera correcta en las columnas

		}

	}

	delete v;

}

MatrizCampo* ProcesaCompuesto::getMatriz() {

	return m;

}