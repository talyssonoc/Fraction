# C++ lib for use of Fractions instead of float type

```cpp
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
			// Writes "Error: Division by zero [3/5 / 0/1]"
		}

		Fraction result5 = f1 + f2;
		std::cout << f1 << " + " << f2 << " = " << result5 << std::endl;

		int i4 = 7;
		Fraction result6 = f1 + i4;
		std::cout << f1 << " + " << i4 << " = " << result6 << std::endl;

		Fraction result7 = f1 - f2;
		std::cout << f1 << " - " << f2 << " = " << result7 << std::endl;

		int i5 = 11;
		Fraction result8 = f1 - i5;
		std::cout << f1 << " - " << i4 << " = " << result8 << std::endl;

		Fraction result9 = -f1;
		std::cout << "-" << f1 << " = " << result9 << std::endl;

		return 0;
	}
```

# TODO

* [ ] Fraction(float) constructor
* [x] Multiplication by Fraction
* [x] Multiplication by int
* [x] Division by Fracton
* [x] Division by int
* [x] Sum by Fraction
* [x] Sum by int
* [ ] Mod by Fraction
* [ ] Mod by int
* [x] Subtraction by Fraction
* [x] Subtraction by int
* [x] Negative
* [ ] Normalizer (reduce fraction)
* [x] == with Fraction
* [x] == with Integer
* [?] == with Float
* [x] != with Fraction
* [x] != with Integer
* [?] != with Float
* [x] > with Fraction
* [x] > with Integer
* [x] < with Fraction
* [x] < with Integer
* [x] >= with Fraction
* [x] >= with Integer
* [x] <= with Fraction
* [x] <= with Integer
* [ ] Inverse of operators (integer + Fraction <=> Fraction + integer)
* [x] PI constant (http://turner.faculty.swau.edu/mathematics/materialslibrary/pi/pirat.html)
* [x] MAX_VALUE constant
* [x] MIN_VALUE constant
* [x] Constant ZERO
* [x] Constant ONE
* [x] Change names from dividend/divisor to numerator/denominator
