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
	if(divisor < 0) {
		dividend = -dividend;
		divisor = -divisor;	
	}

	this->dividend = dividend;
	this->divisor = divisor;
}

const Fraction Fraction::ZERO(0);
const Fraction Fraction::ONE(1);
const Fraction Fraction::MAX_VALUE(INT_MAX);
const Fraction Fraction::MIN_VALUE(INT_MIN);
const Fraction Fraction::PI(3126535, 995207);

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

Fraction Fraction::operator+(const Fraction& fraction) {
	int lcm = this->lcm(this->divisor, fraction.divisor);

	return Fraction((this->dividend * (lcm / this->divisor)) +
					(fraction.dividend * (lcm / fraction.divisor)),
					lcm);
}

Fraction Fraction::operator+(const int& integer) {
	
	return Fraction(this->dividend +
					(integer * this->divisor),
					this->divisor);
}

Fraction Fraction::operator-(const Fraction& fraction) {
	int lcm = this->lcm(this->divisor, fraction.divisor);

	return Fraction((this->dividend * (lcm / this->divisor)) -
					(fraction.dividend * (lcm / fraction.divisor)),
					lcm);
}

Fraction Fraction::operator-(const int& integer) {
	
	return Fraction(this->dividend -
					(integer * this->divisor),
					this->divisor);
}

double Fraction::getDoubleValue() const {
	return this->dividend/(double)this->divisor;
}

int Fraction::gcd(int a, int b) {
    for (;;) {
        
        if (a == 0) {
        	return b;
        }

        b %= a;

        if (b == 0) {
        	return a;
        }
        
        a %= b;
    }
}

int Fraction::lcm(int a, int b) {
    int temp = this->gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

const std::string Fraction::toString() const {
	std::stringstream asStream;

	asStream << this->dividend << "/" << this->divisor;

	return asStream.str();
}

void Fraction::checkDivisionByZero(const Fraction& fraction, int possibleZero) const {

	if(possibleZero == 0) {
		std::stringstream cause;
		cause << "Error: Division by zero ["
			<< this->toString()
			<< " / "
			<< fraction.toString()
			<< "]";

		throw FractionException(cause.str());
	}
}