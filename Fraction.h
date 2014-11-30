#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <sstream>

#include "FractionException.h"

class Fraction {

public:
	Fraction();
	Fraction(int);
	Fraction(int, int);

	static const Fraction ZERO;

	Fraction operator*(const Fraction&);
	Fraction operator*(const int& integer);

	Fraction operator/(const Fraction&);
	Fraction operator/(const int& integer);

	const std::string toString();

	friend std::ostream& operator<<(std::ostream &strm, Fraction &fraction) {
	  return strm << fraction.toString();
	}


private:
	int divisor;
	int dividend;

	void checkDivisionByZero(const Fraction&, int);

};


#endif