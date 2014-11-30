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

		return 0;
	}
```

# TODO

* [x] Multiplication by Fraction
* [x] Multiplication by int
* [x] Division by Fracton
* [x] Division by int
* [ ] Sum by Fraction
* [ ] Sum by int
* [ ] Mod by Fraction
* [ ] Mod by int
* [ ] Subtraction by Fraction
* [ ] Subtraction by int
* [ ] Fraction(float) constructor
* [ ] PI constant
* [ ] E constant
* [x] Zero constant
* [x] One constant

# Idea for mod:

Execute the division and check if dividend
is multiple of divisor