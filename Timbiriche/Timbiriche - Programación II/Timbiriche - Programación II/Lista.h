#pragma once
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::endl;

//---------------------------NODO-----------------------------

template <class T>
class Nodo {

private:

	T* inf;
	Nodo* sig;

public:

	Nodo(T* _inf, Nodo* _sig);
	virtual ~Nodo();

	void setInf(T* _inf);
	T* getInf() const;

	void setSig(Nodo* _sig);
	Nodo* getSig() const;

};

template <class T>
Nodo<T>::Nodo(T* _inf, Nodo* _sig) :
	inf(_inf), sig(_sig) {}

template <class T>
Nodo<T>::~Nodo() { delete inf; }

template <class T>
void Nodo<T>::setInf(T* inf) { this->inf = inf; }

template <class T>
T* Nodo<T>::getInf() const { return inf; }

template <class T>
void Nodo<T>::setSig(Nodo* sig) { this->sig = sig; }

template <class T>
Nodo<T>* Nodo<T>::getSig() const { return sig; }

//-----------------------------ITERADOR-----------------------------

template <class T>
class Iterador {

private:

	Nodo<T>* actual;

public:

	Iterador(Nodo<T>*);
	virtual ~Iterador();
	bool masElementos() const;
	T* proxElemento();

};

template <class T>
Iterador<T>::Iterador(Nodo<T>* primero) :
	actual(primero) {}

template <class T>
Iterador<T>::~Iterador() {}

template <class T>
bool Iterador<T>::masElementos() const {

	if (actual != NULL)
		return true;

	return false;

}

template <class T>
T* Iterador<T>::proxElemento() {

	T* aux = NULL;

	if (masElementos()) {

		aux = actual->getInf();
		actual = actual->getSig();

	}

	return aux;

}

//-----------------------------LISTA-----------------------------

template <class T>
class Lista {

private:

    Nodo<T>* primero;
    Nodo<T>* actual;

public:

    Lista();
    virtual ~Lista();
    void limpiaLista();
    void ingresaDePrimero(T*);
    void ingresaDeUltimo(T*);
    T* obtenerElemento(int);
    Iterador<T>* obtenerIterador();
    bool eliminaPrimero();
    bool eliminaElemento(int);
    int canNodos();
    string toString();

};


template <class T>
Lista<T>::Lista() {

    primero = NULL;
    actual = NULL;

}

template <class T>
Lista<T>::~Lista() {

    limpiaLista();

}

template <class T>
void Lista<T>::limpiaLista() {

    while (primero != NULL) {

        actual = primero;
        primero = primero->getSig();
        delete actual;

    }

}

template <class T>
void Lista<T>::ingresaDePrimero(T* inf) {

    primero = new Nodo<T>(inf, primero);

}

template <class T>
void Lista<T>::ingresaDeUltimo(T* inf) {

    actual = primero;

    if (actual == NULL) {

        ingresaDePrimero(inf);

    }
    else {

        Nodo<T>* nuevo = new Nodo<T>(inf, NULL);

        while (actual->getSig() != NULL) {

            actual = actual->getSig();

        }

        actual->setSig(nuevo);

    }


}

template <class T>
T* Lista<T>::obtenerElemento(int pos) {

    int cont = 1;

    actual = primero;

    while (actual != NULL && cont < pos) {

        actual = actual->getSig();
        cont++;

    }

    if (cont == pos)
       return actual->getInf();

    return NULL;

}


template <class T>
Iterador<T>* Lista<T>::obtenerIterador() {

    return new Iterador<T>(primero);

}

template <class T>
bool Lista<T>::eliminaPrimero() {

    if (primero != NULL) {

        actual = primero;
        primero = primero->getSig();
        delete actual;
        return true;
    }

    return false;

}

template <class T>
bool Lista<T>::eliminaElemento(int pos) {

    int cont = 1;
    actual = primero;

    if (actual != NULL) {

        Nodo<T>* anterior = NULL;

        while (actual != NULL && cont < pos) {

            anterior = actual;
            actual = actual->getSig();
            cont++;

        }

        if (anterior == NULL) {

            return eliminaPrimero();

        }
        else {

            anterior->setSig(actual->getSig());
            delete actual;
            return true;

        }


    }

    return false;

}

template <class T>
int Lista<T>::canNodos() {

    int cont = 0;

    actual = primero;

    while (actual != NULL) {

        cont++;
        actual = actual->getSig();

    }

    return cont;

}

template <class T>
string Lista<T>::toString() {

    actual = primero;
    int cont = 1;

    stringstream d;

    d << "----------LISTADO----------" << endl << endl;

    if (actual == NULL) {

        d << "\tNO HAY ELEMENTOS EN LA LISTA" << endl << endl;

    }
    else {

        while (actual != NULL) {

            d << "No." << cont << ":" << endl << *actual->getInf() << endl << endl;
            actual = actual->getSig();
            cont++;

        }

    }

    d << "---------------------------" << endl;

    return d.str();

}