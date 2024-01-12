#pragma once

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &another);
		ScalarConverter &operator=(const ScalarConverter &another);


	public:
		void	convert(std::string input);



};