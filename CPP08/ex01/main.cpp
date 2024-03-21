#include "Span.hpp"
#include <iostream>

int main()
{
	//from subject
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	//own test with fillSpan to populate a bigger vector
	{
		Span sp(10);
		sp.fillSpan();

		
		std::cout << std::endl << "the vector has: " << std::endl;
		sp.printVec();

		std::cout << std::endl << "the shortest and longest spans are: " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}

