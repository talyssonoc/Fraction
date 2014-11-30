#ifndef FRACTION_E_H
#define FRACTION_E_H

#include <stdexcept>
#include <string>

using namespace std;

class FractionException : public runtime_error {

public:
	FractionException (const string &err) : runtime_error(err) {}
};

#endif