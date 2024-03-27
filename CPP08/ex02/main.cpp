#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(16);
		mstack.push(17);
		std::cout << "top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(736);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "\n with iterators: \n" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		const MutantStack<int> cstack(mstack);

		MutantStack<int>::const_iterator cit = cstack.cbegin();
		MutantStack<int>::const_iterator cite = cstack.cend();

		++cit;
		--cit;

		std::cout << "\n with constant iterators: \n" << std::endl;
		while (cit != cite)
		{
			std::cout << *cit << std::endl;
			++cit;
		}

		std::stack<int> s(mstack);
	}

	std::cout << "\n for comparison here is the list: \n" << std::endl;
	{
		std::list<int> mlist;

		mlist.push_back(5);
		mlist.push_back(16);
		mlist.push_back(17);
		std::cout << "back: " << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << "size: " << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(736);
		mlist.push_back(0);

		std::list<int>::iterator lit = mlist.begin();
		std::list<int>::iterator lite = mlist.end();

		++lit;
		--lit;

		while (lit != lite)
		{
			std::cout << *lit << std::endl;
			++lit;
		}
	}
	return 0;
}
