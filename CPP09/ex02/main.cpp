#include <iostream>
#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		std::vector<int> vec = PmergeMe::validateInputCreateContainer<std::vector>(argc, argv);
		PmergeMe::printContainer(vec);
	}
	catch (std::logic_error)
	{

	}
	// std::cout << "\nvector:: \n" << std::endl;
	// std::vector<int> vec = {1, 2, 3, 4, 5};

	// std::cout << "\ndeque:: \n" << std::endl;

	// std::deque<int> dec = {8, 8, 9, 6, 10};
	// PmergeMe::printContainer(dec);


	// PmergeMe::mergeInsertionSort(vec);
	// PmergeMe::mergeInsertionSort(dec);

	return 0;
}
