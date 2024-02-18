#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_array;

	public:
		Array();
		~Array();
		Array(const Array &another);
		Array& operator=(const Array &another);

		T &operator[](unsigned int index);
		Array(unsigned int size);
		unsigned int size(void);

		class OutOfBouds : public std::exception
		{
			virtual const char *what(void) const throw();
		};
};

#include "Array.tpp"
