#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
	int					number;
	const static int 	bits = 8;

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

	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;

	Fixed &operator+(const Fixed &fixed) ;
	Fixed &operator-(const Fixed &fixed) ;
	Fixed &operator*(const Fixed &fixed) ;
	Fixed &operator/(const Fixed &fixed) ;

	Fixed& operator++(void);
	Fixed& operator--(void);
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(const Fixed &number1, const Fixed &number2);
	static Fixed& max(const Fixed &number1, const Fixed &number2);
	static Fixed& min(Fixed &number1, Fixed &number2);
	static Fixed& max(Fixed &number1, Fixed &number2);

};

std::ostream	&operator<<(std::ostream &string, Fixed const &fixed);

#endif
