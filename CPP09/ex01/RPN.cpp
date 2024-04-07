#include "RPN.hpp"

int RPN::calculate(int first, int second, char op)
{
	switch(op)
	{
		case '+' :
		{
			int res = first + second;
			_stack.push(res);
			break;
		}

		case '-' :
		{
			int res = first - second;
			_stack.push(res);
			break;
		}

		case '*' :
		{
			int res = first * second;
			_stack.push(res);
			break;
		}

		case '/' :
		{
			int res = first / second;
			_stack.push(res);
			break;
		}

		default :
		{
			throw std::logic_error("Operator not recognized");
		}
	}
	return 0;
}

void RPN::reversePolishNotation(std::string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		try
		{
			char c = input[i];
			if (std::isdigit(c))
			{
				std::string s = std::to_string(c);
				int i = stoi(s);
				_stack.push(i);
			}
			if (c == '*' || c == '/' || c == '+' || c == '-')
			{
				int first = _stack.top();
				_stack.pop();
				int second = _stack.top();
				_stack.pop();
				calculate(first, second, c);
			}
			if (std::isspace(c))
				continue;
			else 
				throw std::logic_error("Something went wrong"); 
			
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		std::cout << "Operands did not match match operator count to perform actions" << std::endl;
}
