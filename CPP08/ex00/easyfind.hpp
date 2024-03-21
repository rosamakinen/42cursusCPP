#pragma once

#include <exception>
#include <algorithm>

class NotFound : public std::exception
{
	const char *what () const throw () 
	{ 
		return "Number not found"; 
	}
};

template <typename T>
int easyfind(T &container, int number)
{
	typename T::iterator it = std::find(container.begin(), container.end(), number);
	if (it == container.end())
		throw NotFound();
	return *it;
}