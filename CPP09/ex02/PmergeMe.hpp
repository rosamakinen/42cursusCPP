#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <string>
#include <utility>

class PmergeMe
{

	public:
		template <template <typename...> class Container>
		static Container<unsigned int> validateInputCreateContainer(int argc, char **argv)
		{
			Container<unsigned int> holder;

			for (int i = 1; i < argc; i++)
			{
					int number = std::stoi(argv[i]);
					if (number >= 0)
						holder.push_back(number);
					else
						throw std::logic_error("allowed only digits as input");
			}
			return holder;
		};

		template <template <typename...> class Container>
		static void printContainer(const Container<unsigned int> &container)
		{
			for (typename Container <unsigned int>::iterator it = container.begin(); it != container.end(); it++)
			{
				std::cout << it << std::endl;
			}
		};

		template <template <typename...> class Container>
		static void mergeInsertionSort(const Container<unsigned int> &container)
		{
			//check first if has even or odd amout of numbers
			typename Container <std::pair<unsigned int, unsigned int>> pairContainer;
			typename Container <unsigned int> aChain; //main chain, bigger numers (it.firsts)
			typename Container <unsigned int> bChain; // side chain, smaller numbers (it.seconds)
			for (int i = 0; i < container.size/2; i = i + 2)
			{
				pairContainer.push_back(std::make_pair(i, i+1));
			}
			for (typename Container <std::pair<unsigned int, unsigned int>>::iterator it = pairContainer.begin(); it != pairContainer.end(); it++)
			(
				if (it.first < it.second) // will I benefit from this switcharoo at all? should I just push to the two different chains straight up?
				{
					typename Container<unsigned int> temp;
					temp = it.first;
					it.first = it.second;
					it.second = temp;
				}
				aChain.push_back(it.first); // after sorting holds all the big numbers of the pairs
				bChain.push_back(it.second); // holds all the small numbers of the chains
			)
			sortMainChain(pairContainer); //recursively sort by max value
			// sort 
		};

		template <template <typename...> class Container>
		static void sortMainChain(typename Container <std::pair<unsigned int, unsigned int>> pairContainer)
		{
			int middle =  // find midpoint
			sortMainChain(pairContainer);
			sortMainChain(pariContainer);
			merge();
		};

		// template <template <typename...> class Container>
		// static void mergeInsertionSort(const Container<int> &container)
		// {
		// 		Container<std::pair<int, int>> pairs;

		// };

};