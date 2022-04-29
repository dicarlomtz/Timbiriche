#include "Excepcion.h"

OutOfRangeException::OutOfRangeException(int min, int max) : 
	min(min), max(max){}

string ExistPlayerException::toString() {

	stringstream s;

	s << "-El jugador ya se encuentra registrado-" << endl;

	return s.str();

}

string NoExistPlayerException::toString() {

	stringstream s;

	s << "-El jugador no se encuentra registrado-" << endl;

	return s.str();

}


string OutOfRangeException::toString() {

	stringstream s;

	s << "-El dato ingresado se encuentra fuera del limite permitido-" << endl
		<< "-El minimo permitido es " << min << " y el maximo permitido es " << max << endl;

	return s.str();

}

string TypeOfDataException::toString() {

	stringstream s;

	s << "-El dato ingresado no es del tipo solicitado-" << endl;

	return s.str();

}

string NoOtherPlayerExist::toString() {

	stringstream s;

	s << "-No hay mas jugadores registrados, escoga otro modo de juego-" << endl;

	return s.str();

}