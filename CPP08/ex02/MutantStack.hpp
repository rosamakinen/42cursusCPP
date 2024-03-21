#pragma once

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack &another)
		{
			std::stack<T>::operator=(another);
			return *this
		}
		MutantStack &operator=(const MutantStack &another)
		{
			*this = another;
		}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin()
		{
			return (std::stack<T>::c.begin)
		}
		const_iterator begin()
		{
			return (std::stack<T>::c.begin)
		}
		iterator end()
		{
			return (std::stack<T>::c.end)
		}
		const_iterator end()
		{
			return (std::stack<T>::c.end)
		}
};

std::ostream operator<<(std::ostream &o, MutantStack<T> const &mstack) {};

