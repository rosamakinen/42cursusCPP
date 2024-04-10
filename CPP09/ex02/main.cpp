#include <iostream>
#include "PmergeMe.hpp"

int	main()
{
	std::vector<int> vec = {1, 2, 3, 4, 5};
	PmergeMe::printContainer(vec);

	std::deque<int> dec = {8, 8, 9, 6, 10};
	PmergeMe::printContainer(dec);



	// PmergeMe::mergeInsertionSort(vec);
	// PmergeMe::mergeInsertionSort(dec);

	return 0;
}
