#include <iostream>
#include <exception>

#include "Fraction.h"

int main() {

	Fraction f1(1, 2);
	Fraction f2(3, 5);

	Fraction result1 = f1 * f2;
	std::cout << f1 << " * " << f2 << " = " << result1 << std::endl;

	int i1 = 7;
	Fraction result2 = f1 * i1;
	std::cout << f1 << " * " << i1 << " = " << result2 << std::endl;

	int i2 = 2;
	Fraction result3 = f2 / i2;
	std::cout << f2 << " / " << i2 << " = " << result3 << std::endl;

	try {
		int i3 = 0;
		Fraction result4 = f2 / i3;
		std::cout << f2 << " / " << i3 << " = " << result4 << std::endl;
	}
	catch(exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}