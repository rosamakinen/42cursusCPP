#include <iostream>
#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		std::vector<unsigned int> vec = PmergeMe::validateInputCreateContainer<std::vector>(argc, argv);
		std::cout << "\nvector:: \n" << std::endl;
		PmergeMe::printContainer(vec);
		PmergeMe::mergeInsertionSort<std::vector>(vec);
	}
	catch (std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
	}

	// std::cout << "\ndeque:: \n" << std::endl;

	// std::deque<int> dec = {8, 8, 9, 6, 10};
	// PmergeMe::printContainer(dec);


	// PmergeMe::mergeInsertionSort(dec);

	return 0;
}
