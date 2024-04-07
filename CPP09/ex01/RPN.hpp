#pragma once

#include <string>
#include <iterator>
#include <stack>
#include <iostream>
#include <cmath>
#include <locale>

class RPN 
{

	private:
		std::stack<int> _stack;
		int calculate(int first, int second, char op);

	public:
		RPN();
		RPN(RPN const &another);
		~RPN();
		RPN &operator=(RPN const &another);

		void reversePolishNotation(std::string input);




};