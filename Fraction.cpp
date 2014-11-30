#include "Fraction.h"

Fraction::Fraction() {
	this->dividend = 0;
	this->divisor = 1;
}

Fraction::Fraction(int dividend) {
	this->dividend = dividend;
	this->divisor = 1;
}

Fraction::Fraction(int dividend, int divisor) {
	this->dividend = dividend;
	this->divisor = divisor;
}

Fraction Fraction::operator*(Fraction& fraction) {
	return Fraction(this->dividend * fraction.dividend,
					this->divisor * fraction.divisor);
}