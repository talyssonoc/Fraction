#include "Fraction.h"

Fraction::Fraction() {
	this->numerator = 0;
	this->denominator = 1;
}

Fraction::Fraction(int numerator) {
	this->numerator = numerator;
	this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {

	this->numerator = numerator;
	this->denominator = denominator;

	this->simplify();
}

/**
 *	Explanation:
 *
 *	We get the mantissa (mt), the exponent (n)
 *	that represents the float number and the
 *	number of decimal digits of the mantissa (m)
 *
 * 	So we turn it in the form:
 *
 * 	number = ((10^m * mt) * 2^n) / (10 ^ m)
 *
 * So, before calculate the exponentiations,
 * we simplify z = (2^n)/(10^m) by turning it doing:
 * 
 * h = min(n, m)
 *
 * z = (2^(n-h))/(5^h * 10^(m-h))
 *
 * Then we'll have the numerator and the denominator,
 * that we simplify by dividing them by them GCD.
 * 
 */
Fraction::Fraction(float number) {
	float mantissa;

	int exponent,
		numerator,
		denominator,
		h;

	// Mantissa of the floating number
	mantissa = frexp(number , &exponent);

	// E.g. turns 0.123 into 123
	numerator = this->mantissaToInteger(mantissa, &denominator);

	h = min(denominator, exponent);

	// Simplify (2^n)/(10^m)
	this->numerator = numerator * pow(2, exponent - h);
	this->denominator = pow(5, h) * pow(10, denominator - h);

	this->simplify();
}

const Fraction Fraction::ZERO(0);
const Fraction Fraction::ONE(1);
const Fraction Fraction::MAX_VALUE(INT_MAX);
const Fraction Fraction::MIN_VALUE(INT_MIN);
const Fraction Fraction::PI(3126535, 995207);

Fraction Fraction::operator-() {
	return Fraction(-this->numerator,
					this->denominator);
}

Fraction Fraction::operator+(const Fraction& fraction) {
	return this->commonOperation((*this), fraction, std::plus<int>());
}

Fraction Fraction::operator+(const int& integer) {
	return this->commonOperation((*this), integer, std::plus<int>());	
}

Fraction Fraction::operator-(const Fraction& fraction) {
	return this->commonOperation((*this), fraction, std::minus<int>());
}

Fraction Fraction::operator-(const int& integer) {
	return this->commonOperation((*this), integer, std::minus<int>());
}

Fraction Fraction::operator*(const Fraction& fraction) {
	Fraction result(this->numerator * fraction.numerator,
					this->denominator * fraction.denominator);

	result.simplify();

	return result;
}

Fraction Fraction::operator*(const int& integer) {
	Fraction result(this->numerator * integer,
					this->denominator);

	result.simplify();

	return result;
}

Fraction Fraction::operator/(const Fraction& fraction) {
	this->checkDivisionByZero(fraction, fraction.numerator);

	Fraction result(this->numerator * fraction.denominator,
					this->denominator * fraction.numerator);

	result.simplify();

	return result;
}

Fraction Fraction::operator/(const int& integer) {
	this->checkDivisionByZero(Fraction::ZERO, integer);

	Fraction result(this->numerator,
					this->denominator * integer);

	result.simplify();

	return result;
}

int Fraction::operator%(const Fraction& fraction) {
	Fraction division = (*this) / fraction;

	int integer = (int) division.getFloatValue();

	integer = division.denominator * integer;

	return division.numerator - integer; 
}

int Fraction::operator%(const int& integer) {
	Fraction division = (*this) / integer;

	int integerPart = (int) division.getFloatValue();

	integerPart = division.denominator * integerPart;

	return division.numerator - integerPart; 
}

bool Fraction::operator==(const Fraction& fraction) {
	return this->comparison((*this), fraction, std::equal_to<int>());
}

bool Fraction::operator==(const int& integer) {
	return this->comparison((*this), integer, std::equal_to<int>());
}

bool Fraction::operator!=(const Fraction& fraction) {
	return this->comparison((*this), fraction, std::not_equal_to<int>());
}

bool Fraction::operator!=(const int& integer) {
	return this->comparison((*this), integer, std::not_equal_to<int>());
}

bool Fraction::operator>(const Fraction& fraction) {
	return this->comparison((*this), fraction, std::greater<int>());
}

bool Fraction::operator>(const int& integer) {
	return this->comparison((*this), integer, std::greater<int>());
}

bool Fraction::operator<(const Fraction& fraction) {
	return this->comparison((*this), fraction, std::less<int>());
}

bool Fraction::operator<(const int& integer) {
	return this->comparison((*this), integer, std::less<int>());
}

bool Fraction::operator>=(const Fraction& fraction) {
	return this->comparison((*this), fraction, std::greater_equal<int>());
}

bool Fraction::operator>=(const int& integer) {
	return this->comparison((*this), integer, std::greater_equal<int>());
}

bool Fraction::operator<=(const Fraction& fraction) {
	return this->comparison((*this), fraction, std::less_equal<int>());
}

bool Fraction::operator<=(const int& integer) {
	return this->comparison((*this), integer, std::less_equal<int>());
}

double Fraction::getDoubleValue() const {
	return this->numerator/(double)this->denominator;
}

float Fraction::getFloatValue() const {
	return this->numerator/(float)this->denominator;
}

int Fraction::gcd(int a, int b) const {
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

int Fraction::lcm(int a, int b) const {
    int gcd = this->gcd(a, b);

    return gcd ? (a / gcd * b) : 0;
}

int Fraction::mantissaToInteger(float mantissa, int* n) const {
	*n = 0;

	while(mantissa != (int) mantissa) {
		mantissa *= 10;
		*n += 1;
	}

	return mantissa;
}

void Fraction::simplify() {
	int gcd = this->gcd(this->numerator, this->denominator);
	
	this->numerator /= gcd;
	this->denominator /= gcd;

	if(this->denominator < 0) {
		this->numerator = -this->numerator;
		this->denominator = -this->denominator;
	}
}

const std::string Fraction::toString() const {
	std::stringstream asStream;

	asStream << this->numerator << "/" << this->denominator;

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