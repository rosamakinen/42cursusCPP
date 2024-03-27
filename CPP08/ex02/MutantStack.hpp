#pragma once

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(MutantStack const &another)
		{
			*this = another;
		}

		MutantStack &operator=(MutantStack const &another)
		{
			std::stack<T>::operator=(another);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}

		const_iterator cbegin() const
		{
			return (this->c.cbegin());
		}

		const_iterator cend() const
		{
			return (this->c.cend());
		}


};


