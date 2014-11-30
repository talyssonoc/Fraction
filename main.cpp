#include <iostream>

#include "Fraction.h"

int main() {

	Fraction f1(1, 2);
	Fraction f2(3, 5);

	Fraction result = f1 * f2;

	std::cout << f1 << " * " << f2 << " = " << result << std::endl;

	return 0;
}