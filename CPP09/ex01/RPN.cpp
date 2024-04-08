#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const &another)
{
	*this = another;
}

RPN &RPN::operator=(RPN const &another)
{
	if (this != &another)
	{
		this->_stack = another._stack;
	}
	return *this;
}

int RPN::calculate(int first, int second, char op)
{
	switch(op)
	{
		case '+' :
		{
			int res = first + second;
			_stack.push(res);
			std::cout << "res: " << res << std::endl;
			break;
		}

		case '-' :
		{
			int res = first - second;
			_stack.push(res);
			std::cout << "res: " << res << std::endl;
			break;
		}

		case '*' :
		{
			int res = first * second;
			_stack.push(res);
			std::cout << "res: " << res << std::endl;
			break;
		}

		case '/' :
		{
			int res = first / second;
			_stack.push(res);
			std::cout << "res: " << res << std::endl;
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
	for (size_t i = 0; i < input.length(); i++)
	{
		try
		{
			char c = input[i];
			if (std::isdigit(c))
			{
				std::string s = std::to_string(c - '0');
				std::cout << "pushing to stack: " << s << std::endl;
				int i = stoi(s);
				_stack.push(i);
			}
			else if (c == '*' || c == '/' || c == '+' || c == '-')
			{
				std::cout << "found operand: " << c << std::endl;
				if (_stack.size() == 2)
				{
					int first = _stack.top();
					_stack.pop();
					int second = _stack.top();
					_stack.pop();
					calculate(first, second, c);
				}
				else
					throw std::logic_error("Not enough values to calculate");

			}
			else if (std::isspace(c))
				continue;
			else
				throw std::logic_error("Unknown operand");

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return ;
		}
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else
		std::cout << "Operator count did not match the value count to perform all actions. \n Stack has: " << _stack.size() << " values left in it." << std::endl;
}
