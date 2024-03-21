#pragma once

#include <vector>
#include <cmath>
#include <exception>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>


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
		void fillSpan();
		void printVec();
};

std::ostream &operator<<(std::ostream &o, const Span &span);