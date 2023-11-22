#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

	int	getRawBits(void) const;
	void setRawBits(const int bits);
};

#endif