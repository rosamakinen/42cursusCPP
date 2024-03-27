#include "Span.hpp"
#include <iostream>
#include <list>

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

	//own test with fillSpan to populate any bigger vector
	{
		Span sp = Span(15);
		std::list<int> itertest = {1,2,3,4,5,6,7,8,9,10,11,12,13,20,25};

		std::list<int>::iterator begin = itertest.begin();
		std::list<int>::iterator end = itertest.end();
		sp.addNumbers(begin, end);

		std::cout << std::endl << "the vector has: " << std::endl;
		sp.printVec();

		std::cout << std::endl << "the shortest and longest spans are: " << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}

