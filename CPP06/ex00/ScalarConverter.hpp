#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	enum TYPE
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		NAN,
		INF
	};

	private:
		static ScalarConverter::TYPE	findType(std::string input);
		static void						printConversion(char c, int i, float f, double d);
		static void 					printChar(char c);
		static void 					printInt(int i);
		static void 					printFloat(float f);
		static void 					printDouble(double d);

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &another);
		ScalarConverter &operator=(const ScalarConverter &another);

		static void	convert(std::string input);

};
