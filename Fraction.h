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

	static Fraction ZERO;

	Fraction operator*(Fraction&);
	Fraction operator*(int& integer);

	Fraction operator/(Fraction&);
	Fraction operator/(int& integer);

	friend std::ostream& operator<<(std::ostream &strm, const Fraction &fraction) {
	  return strm << fraction.dividend << "/" << fraction.divisor;
	}

	std::string toString();

private:
	int divisor;
	int dividend;

	void checkDivisionByZero(Fraction&, int);

};


#endif