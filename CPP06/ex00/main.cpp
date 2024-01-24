#include <string>
#include "ScalarConverter.hpp"

int main()
{
	std::string 	c = "55";   //char
	std::string		i = "2236756";     // int
	std::string		f = "12344.44321f";  // float
	// std::string		fl = "aheirhoaeirihnoernih";  // float
	std::string		fl = "9387913333338274918741.10701047012974012f";  // float
	std::string		d = "12.21"; // double
	std::string		nan = "nanf"; // double
	std::string		inf = "-inf"; // double
	std::string		inff = "+inff"; // double

	std::cout << "\nchar" << std::endl;
	ScalarConverter::convert(c);
	std::cout << "\nint" << std::endl;
	ScalarConverter::convert(i);
	std::cout << "\nfloat" << std::endl;
	ScalarConverter::convert(f);
	std::cout << "\nmassive float" << std::endl;
	ScalarConverter::convert(fl);
	std::cout << "\ndouble" << std::endl;
	ScalarConverter::convert(d);
	std::cout << "\nnan" << std::endl;
	ScalarConverter::convert(nan);
	std::cout << "\n-inf" << std::endl;;
	ScalarConverter::convert(inf);
	std::cout << "\n+inff" << std::endl;
	ScalarConverter::convert(inff);

	return 0;
}
