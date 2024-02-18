#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _array(NULL)
{
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

template <typename T>
Array<T>::Array(const Array &another) : _size(another._size), _array(new T[another._size])
{
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = another._array[i];
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n])
{
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &another)
{
	if (this != &another)
	{
		delete[] _array;
		_size = another._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = another._array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw Array::OutOfBouds();

	return _array[index];
}

template <typename T>
unsigned int Array<T>::size(void)
{
	return _size;
}

template <typename T>
const char *Array<T>::OutOfBouds::what(void) const throw()
{
	return "Sorry pal, element out of bounds!";
}