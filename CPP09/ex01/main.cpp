#include "RPN.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN rpn;
		if (argv[1])
		{
			std::string input(argv[1]);
			rpn.reversePolishNotation(input);
		}
	}
	else
		std::cout << "please give input string: '5 3 + 2 -' " << std::endl;
	return 0;
}
