#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <sstream>
#include <climits>
#include <cmath>
#include <iomanip>
#include <functional>

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

	// Negative
	Fraction operator-();

	// Common operations
	Fraction operator+(const Fraction&);
	Fraction operator+(const int&);

	Fraction operator-(const Fraction&);
	Fraction operator-(const int&);

	Fraction operator*(const Fraction&);
	Fraction operator*(const int&);

	Fraction operator/(const Fraction&);
	Fraction operator/(const int&);

	// Comparators
	bool operator==(const Fraction&);
	bool operator==(const int&);

	bool operator!=(const Fraction&);
	bool operator!=(const int&);

	bool operator>(const Fraction&);
	bool operator>(const int&);

	bool operator<(const Fraction&);
	bool operator<(const int&);

	bool operator>=(const Fraction&);
	bool operator>=(const int&);

	bool operator<=(const Fraction&);
	bool operator<=(const int&);

	double getDoubleValue() const ;
	float getFloatValue() const ;

	const std::string toString() const;

	friend std::ostream& operator<<(std::ostream &strm, Fraction fraction) {
	  return strm << fraction.toString();
	}

private:
	int numerator;
	int denominator;

	// numerator/denominator

	void checkDivisionByZero(const Fraction&, int) const;
	int gcd(int, int) const;
	int lcm(int, int) const;

	// Generic functional comparator
	template <typename ComparisonOperator>
	bool comparison(const Fraction& f1,
					const Fraction& f2,
					ComparisonOperator operation) {

		if(f1.denominator == f2.denominator) {
			return operation(f1.numerator, f2.numerator);
		}

		int lcm = f1.lcm(f1.denominator, f2.denominator);

		return operation(f1.numerator * (lcm / f1.denominator),
						f2.numerator * (lcm / f2.denominator));
	}

	template <typename ComparisonOperator>
	bool comparison(const Fraction& f1,
					const int& i1,
					ComparisonOperator operation) {

		if(this->denominator == 1) {
			return this->numerator == i1;
		}

		return operation(this->numerator,
						i1 * this->denominator);
	}

	template<typename PlusMinusOperator>
	Fraction commonOperation(const Fraction& f1,
							 const Fraction& f2,
							 PlusMinusOperator operation) {

		int lcm = f1.lcm(f1.denominator, f2.denominator);

		return Fraction(
				operation(
					f1.numerator * (lcm / f1.denominator),
					f2.numerator * (lcm / f2.denominator)
				), lcm);
	}

	template<typename PlusMinusOperator>
	Fraction commonOperation(const Fraction& f1,
							 const int& i1,
							 PlusMinusOperator operation) {
		return Fraction(
				operation(
					f1.numerator,
					i1 * f1.denominator
				), f1.denominator);
	}

};


#endif