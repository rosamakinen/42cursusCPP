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

Fixed::Fixed(const int param)
{
	std::cout << "Fixed int constructor called" << std::endl;
	this->number = param << bits;
}

Fixed::Fixed(const float param)
{
	std::cout << "Fixed float constructor called" << std::endl;
	this->number = std::roundf(param * (1 << bits));
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


float Fixed::toFloat(void) const
{
	float ret = static_cast<float>(this->number) / (1 << this->bits);
	return (ret);
}

int Fixed::toInt(void) const
{
	return this->number >> this->bits;
}

std::ostream &operator<<(std::ostream &string, Fixed const &fixed)
{
	return (string << fixed.toFloat());
}
