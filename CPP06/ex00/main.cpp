#include <string>
#include "ScalarConverter.hpp"

int main()
{
	std::string 	c = "c";   //char
	std::string		i = "6";     // int
	std::string		f = "1.0f";  // float
	std::string		d = "12.21"; // double

	ScalarConverter::convert(c);

}