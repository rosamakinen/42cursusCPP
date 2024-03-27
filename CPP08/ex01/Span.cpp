#include "Span.hpp"

Span::~Span()
{
}

Span::Span()
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span & another) : _vector(another._vector), _maxSize(another._maxSize)
{
}

Span & Span::operator=(const Span & another)
{
	if (this != &another)
	{
		_maxSize = another._maxSize;
		_vector = another._vector;
	}
	return *this;
}

void Span::addNumber(unsigned int n)
{
	if (this->_vector.size() >= getMaxSize())
		throw std::runtime_error("Container max size reached");
	this->_vector.push_back(n);
}

int Span::shortestSpan() const
{
	if (this->_vector.size() == 0 || this->_vector.size() == 1)
		throw std::runtime_error("Container needs to have at least two values");
	std::vector<int> temp = _vector;
	std::sort(temp.begin(), temp.end());
	int shortest = std::abs(temp[1] - temp[0]);

	for (size_t i = 1; i < temp.size(); i++)
	{
		int newShortest = std::abs(temp[i] - temp[i - 1]);
		if (newShortest < shortest)
			shortest = newShortest;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (this->_vector.size() == 0 || this->_vector.size() == 1)
		throw std::runtime_error("Container needs to have at least two values");
	int ret = *std::max_element(this->_vector.begin(), this->_vector.end()) -
	*std::min_element(this->_vector.begin(), this->_vector.end());
	return ret;
}

unsigned int Span::getMaxSize()
{
	return this->_maxSize;
}

void Span::addNumbers(std::list<int>::const_iterator start, std::list<int>::const_iterator end)
{
	for (std::list<int>::const_iterator ite = start; ite != end; ite++)
	{
		this->_vector.push_back(*ite);
	}
}

void Span::printVec()
{
	for (size_t i = 0; i != this->getMaxSize(); i++)
			std::cout << this->_vector[i] << std::endl;
}

std::ostream & operator<<(std::ostream & o, const Span & container)
{
	o << container.shortestSpan();
	o << container.longestSpan();

	return o;
}

