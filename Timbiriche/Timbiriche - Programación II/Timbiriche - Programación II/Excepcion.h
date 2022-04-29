#pragma once
#include <iostream>
#include <sstream>
#include <string>
using std::string;
using std::stringstream;
using std::endl;

class Exception {

public:

	virtual string toString() = 0;

};

class ExistPlayerException : public Exception {

public:

	string toString();

};

class NoExistPlayerException : public Exception {


public:

	string toString();

};

class OutOfRangeException : public Exception {

private:

	int min;
	int max;

public:

	OutOfRangeException(int, int);

	string toString();

};

class TypeOfDataException : public Exception {

public:

	string toString();

};

class NoOtherPlayerExist : public Exception {

public:

	string toString();

};