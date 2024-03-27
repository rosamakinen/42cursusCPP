#pragma once

#include <vector>
#include <cmath>
#include <exception>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>


class Span
{
	private:
		Span();
		std::vector<int> _vector;
		unsigned int _maxSize;

	public:
		~Span();
		Span(unsigned int N);
		Span(const Span &another);
		Span &operator=(const Span &another);

		void addNumber(unsigned int n);
		int shortestSpan() const;
		int longestSpan() const;
		unsigned int getMaxSize();
		void addNumbers(std::list<int>::const_iterator start, std::list<int>::const_iterator end);
		void printVec();
		std::list<int> fillList(int listSize);
};

std::ostream &operator<<(std::ostream &o, const Span &span);
