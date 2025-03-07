#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << "\n" << std::endl;
	std::cout << ++a << "\n" << std::endl;
	std::cout << a << "\n" << std::endl;
	std::cout << a++ << "\n" << std::endl;
	std::cout << a << "\n" << std::endl;
	std::cout << b << "\n" << std::endl;
	std::cout << Fixed::max(a, b) << "\n" << std::endl;
	std::cout << Fixed::max(a, a) << "\n" << std::endl;
	std::cout << Fixed::max(b, b) << "\n" << std::endl;
	std::cout << Fixed::max(b, a) << "\n" << std::endl;
	std::cout << Fixed::min(a, b) << "\n" << std::endl;
	std::cout << Fixed::min(a, a) << "\n" << std::endl;
	std::cout << Fixed::min(b, b) << "\n" << std::endl;
	std::cout << Fixed::min(b, a) << "\n" << std::endl;
	
	std::cout << "comparison a < b is " << (a < b) << "\n" << std::endl;
	std::cout << "comparison a > b is " << (a > b) << "\n" << std::endl;
	std::cout << "comparison a <= b is " << (a <= b) << "\n" << std::endl;
	std::cout << "comparison a >= b is " << (a >= b) << "\n" << std::endl;
	std::cout << "comparison a == b is " << (a == b) << "\n" << std::endl;
	std::cout << "comparison a != b is " << (a != b) << "\n" << std::endl;

	std::cout << "mathematic a + b is " << (a + b) << "\n" << std::endl;
	std::cout << "mathematic a - b is " << (a - b) << "\n" << std::endl;
	std::cout << "mathematic a * b is " << (a * b) << "\n" << std::endl;
	std::cout << "mathematic a / b is " << (a / b) << "\n" << std::endl;

	std::cout << "pre-increment ++a " << (++a) << "\n" << std::endl;
	std::cout << "post-increment a++ " << (a++) << "\n" << std::endl;
	std::cout << "pre-decrement --a " << (--a) << "\n" << std::endl;
	std::cout << "post-decrement a-- " << (a++) << "\n" << std::endl;

	return (0);
}