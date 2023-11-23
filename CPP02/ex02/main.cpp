#include "Fixed.hpp"
#include <iostream>

// int	main(void)
// {
// 	Fixed a = 1;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;

// 	std::cout << a / b << std::endl;
// 	std::cout << a / 2 << std::endl;
// 	std::cout << a + 1.5f << std::endl;
// 	std::cout << a - 0.5f << std::endl;
// 	std::cout << a * 2.0f << std::endl;

// 	std::cout << "Min number: "<<Fixed::min(a, b) << std::endl;
// 	std::cout << "Max number: "<<Fixed::max(a, b) << std::endl;

// 	return 0;
// }

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
