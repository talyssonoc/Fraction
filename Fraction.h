#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
public:
	Fraction();
	Fraction(int);
	Fraction(int, int);

	Fraction operator*(Fraction&);
	// Fraction operator*(int integer);


	friend std::ostream& operator<<(std::ostream &strm, const Fraction &fraction) {
	  return strm << fraction.dividend << "/" << fraction.divisor;
	}

private:
	int divisor;
	int dividend;

};


#endif