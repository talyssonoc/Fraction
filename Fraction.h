#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <sstream>
#include <climits>
#include <iomanip>

#include "FractionException.h"

class Fraction {

public:
	Fraction();
	Fraction(int);
	Fraction(int, int);

	const static Fraction ZERO;
	const static Fraction ONE;
	const static Fraction MAX_VALUE;
	const static Fraction MIN_VALUE;
	const static Fraction PI;

	Fraction operator+(const Fraction&);
	Fraction operator+(const int& integer);

	Fraction operator-(const Fraction&);
	Fraction operator-(const int& integer);

	Fraction operator*(const Fraction&);
	Fraction operator*(const int& integer);

	Fraction operator/(const Fraction&);
	Fraction operator/(const int& integer);

	double getDoubleValue() const ;

	const std::string toString() const;

	friend std::ostream& operator<<(std::ostream &strm, Fraction fraction) {
	  return strm << fraction.toString();
	}


private:
	int divisor;
	int dividend;

	void checkDivisionByZero(const Fraction&, int) const;
	int gcd(int, int);
	int lcm(int, int);

};


#endif