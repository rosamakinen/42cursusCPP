#include <string>
#include "ScalarConverter.hpp"

int main()
{
	std::string 	c = "55";   //char
	std::string		i = "23456356";     // int
	std::string		f = "12344.44321f";  // float
	// std::string		fl = "aheirhoaeirihnoernih";  // float
	std::string		fl = "93878741.107012f";  // float
	std::string		d = "13462.2776"; // double
	std::string		nan = "nanf"; // double
	std::string		inf = "-inf"; // double
	std::string		inff = "+inff"; // double

	std::cout << "\nchar " << c << std::endl;
	ScalarConverter::convert(c);
	std::cout << "\nint " << i << std::endl;
	ScalarConverter::convert(i);
	std::cout << "\nfloat " << f << std::endl;
	ScalarConverter::convert(f);
	std::cout << "\nmassive float " << fl << std::endl;
	ScalarConverter::convert(fl);
	std::cout << "\ndouble " << d << std::endl;
	ScalarConverter::convert(d);
	std::cout << "\nnan " << std::endl;
	ScalarConverter::convert(nan);
	std::cout << "\n-inf " << std::endl;;
	ScalarConverter::convert(inf);
	std::cout << "\n+inff " << std::endl;
	ScalarConverter::convert(inff);

	return 0;
}
