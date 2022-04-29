#pragma once
#include <ostream>
#include <Windows.h>
using namespace std;

/*

Apuntes 

A las funciones inline se les indica que compilen para estar en linea de modo que el compilador pueda remplazar estas definiciones en donde se llamen
El compilador remplaza la definicion de funciones inline en tiempo de compilacion en vez de referir la definicion en tiempo de ejecucion(util para funciones pequeñas)
Esto aumenta la rapidez pero consume mas recurso, por lo cual es mejor en funciones pequeñas

*/

inline ostream& azul(ostream& c) {

	HANDLE salida_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(salida_handle, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	return c;

}

inline ostream& rojo(ostream& c) {

    HANDLE salida_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(salida_handle, FOREGROUND_RED | FOREGROUND_INTENSITY);

    return c;

}

inline ostream& blanco(ostream& c) {

    HANDLE salida_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(salida_handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    return c;

}

inline ostream& verde(ostream& c) {

    HANDLE salida_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(salida_handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    return c;

}