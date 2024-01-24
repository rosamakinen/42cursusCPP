#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &another)
{
	(void)another;
	return *this;
}

ScalarConverter::TYPE	ScalarConverter::findType(std::string input)
{
	if (input.length() == 1)
	{
			return CHAR;
	}
	if (input.find(".") != std::string::npos)
	{
		if (input.find("f") == std::string::npos)
			return FLOAT;
		return DOUBLE;
	}
	if (input.compare("+inf") == 0 || input.compare("-inf") == 0 ||
		input.compare("+inff") == 0 || input.compare("-inff") == 0)
		return INF;
	if (input.compare("nan") == 0 || input.compare("nanf") == 0)
		return NAN;
	return INT;

}

void ScalarConverter::printChar(char c)
{
	if (c < 0 || c > 127)
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printInt(int i)
{
	if (i < std::numeric_limits<int>::lowest() || i > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printFloat(float f)
{
	if (f < std::numeric_limits<float>::lowest() || f > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void ScalarConverter::printDouble(double d)
{
	if (d < std::numeric_limits<double>::lowest() || d > std::numeric_limits<double>::max())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printConversion(char c, int i, float f, double d)
{
	printChar(c);
	printInt(i);
	printFloat(f);
	printDouble(d);
}

void ScalarConverter::convert(std::string input)
{
	ScalarConverter::TYPE type = findType(input);

	char	c = '\0';
	int		i = 0;
	float	f = 0.0f;
	double	d = 0.0;

	try
	{
		switch (type)
		{
			case CHAR:
			{
				c = input[0];
				i = static_cast<int>(c);
				f = static_cast<float>(c);
				d = static_cast<double>(c);
				break ;
			}
			case INT:
			{
				i = std::stoi(input.c_str());
				c = static_cast<char>(i);
				f = static_cast<float>(i);
				d = static_cast<double>(i);
				break ;
			}
			case FLOAT:
			{
				f = std::stof(input.c_str());
				i = static_cast<int>(f);
				c = static_cast<char>(f);
				d = static_cast<double>(f);

				break ;
			}
			case DOUBLE:
			{
				d = std::stod(input.c_str());
				c = static_cast<char>(d);
				i = static_cast<int>(d);
				f = static_cast<float>(d);
				break ;
			}
			case NAN:
			{
				std::cout << "char : impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
				return ;
				break ;
			}
			case INF:
			{
				if (input.compare("-inf") == 0 || input.compare("-inff") == 0)
				{
					std::cout << "char : impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
					return ;
				}
				if (input.compare("+inf") == 0 || input.compare("+inff") == 0)
				{
					std::cout << "char : impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
					return ;
				}
				break ;
			}
			default:
				break ;
		}
	}
	catch(std::invalid_argument const& e)
	{
		std::cout << "we overflowwwwwww" << std::endl;
	}
	catch(std::out_of_range const& e)
	{
		std::cout << "we overflowwwwwww" << std::endl;
	}
	printConversion(c, i, f, d);
}
