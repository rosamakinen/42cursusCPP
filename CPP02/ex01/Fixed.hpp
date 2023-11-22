#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
	int					number;
	const static int 	bits;

	public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &rhs);
	Fixed &operator=(const Fixed &rhs);

	Fixed(const int param);
	Fixed(const float param);

	float	toFloat(void) const;
	int		toInt(void) const;

	int	getRawBits(void) const;
	void setRawBits(const int bits);
};

std::ostream	&operator<<(std::ostream &string, Fixed const &fixed);

#endif