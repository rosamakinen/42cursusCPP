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
		static void						printConversion(char c, int i, float f, double d, bool impC, bool impI, bool impF, bool impD);
		static void 					printChar(char c);
		static void 					printInt(int i);
		static void 					printFloat(float f);
		static void 					printDouble(double d);
		static void 					printImpossible(ScalarConverter::TYPE TYPE);
		static void						checkCastLimitsI(int i, bool &impC, bool &impF, bool &impD);
		static void						checkCastLimitsF(float f, bool &impC, bool &impI, bool &impD);
		static void						checkCastLimitsD(double d, bool &impC, bool &impI, bool &impF);
		ScalarConverter();
		ScalarConverter(const ScalarConverter &another);
		ScalarConverter &operator=(const ScalarConverter &another);

	public:
		~ScalarConverter();

		static void	convert(std::string input);

};
