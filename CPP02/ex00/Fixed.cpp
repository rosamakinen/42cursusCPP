#include "Fixed.hpp"

Fixed::Fixed() : number(0)
{
	std::cout << "Fixed constructed" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Fixed destructed" << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Fixed copy constructor called" << std::endl;
	*this = rhs;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Fetching from copy assignment operator" << std::endl;
	this->number = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "Fetching from getRawBits" << std::endl;
	return this->number;
}

void Fixed::setRawBits(const int rawBits)
{
	this->number = rawBits;
}
