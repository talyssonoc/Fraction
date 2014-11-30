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

const Fraction Fraction::ZERO(0);

Fraction Fraction::operator*(const Fraction& fraction) {
	return Fraction(this->dividend * fraction.dividend,
					this->divisor * fraction.divisor);
}

Fraction Fraction::operator*(const int& integer) {
	return Fraction(this->dividend * integer,
					this->divisor);
}

Fraction Fraction::operator/(const Fraction& fraction) {
	this->checkDivisionByZero(fraction, fraction.dividend);

	return Fraction(this->dividend * fraction.divisor,
					this->divisor * fraction.dividend);
}

Fraction Fraction::operator/(const int& integer) {
	this->checkDivisionByZero(Fraction::ZERO, integer);

	return Fraction(this->dividend,
					this->divisor * integer);
}

const std::string Fraction::toString() {
	std::stringstream asStream;

	asStream << this->dividend << "/" << this->divisor;

	return asStream.str();
}

void Fraction::checkDivisionByZero(const Fraction& fraction, int possibleZero) {

	if(possibleZero == 0) {
		std::stringstream cause;
		cause << "Error: Division by zero";
		/*	<< "["
			<< this->toString()
			<< " / "
			<< fraction.toString()
			<< "]"*/;

		throw FractionException(cause.str());
	}
}