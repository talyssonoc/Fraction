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
	if(denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;	
	}

	this->numerator = numerator;
	this->denominator = denominator;
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
	return Fraction(this->numerator * fraction.numerator,
					this->denominator * fraction.denominator);
}

Fraction Fraction::operator*(const int& integer) {
	return Fraction(this->numerator * integer,
					this->denominator);
}

Fraction Fraction::operator/(const Fraction& fraction) {
	this->checkDivisionByZero(fraction, fraction.numerator);

	return Fraction(this->numerator * fraction.denominator,
					this->denominator * fraction.numerator);
}

Fraction Fraction::operator/(const int& integer) {
	this->checkDivisionByZero(Fraction::ZERO, integer);

	return Fraction(this->numerator,
					this->denominator * integer);
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