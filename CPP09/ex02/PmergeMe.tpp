#include <vector>
#include <deque>
#include <iostream>
#include <exception>
#include "PmergeMe.hpp"


template <template <typename...> class Container>
void PmergeMe::printContainer(const Container<int> &container)
{
	for (const auto& it : container)
	{
		std::cout << it << std::endl;
	}
}

// template <template <typename...> class Container>
// void PmergeMe::mergeInsertionSort(const Container<int> &container)
// {
// 	Container<std::pair<int, int>> pairs;

// }

