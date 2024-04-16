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
	private:


	public:

		template <template <typename...> class Container>
		static void printContainer(const Container<unsigned int> &container)
		{
			for (unsigned int i = 0; i < container.size(); i++)
			{
				std::cout << container[i] << std::endl;
			}
		}

		template <template <typename...> class Container>
		static Container<unsigned int> merge(Container<unsigned int> &mainChain, unsigned int start, unsigned int middle, unsigned int end)
		{
			unsigned int leftSize = middle - start + 1; //up untill, including the middle
			unsigned int rightSize = end - middle; // after middle

			Container<unsigned int> rightChain;
			Container<unsigned int> leftChain;

			for (unsigned int i = 0; i < mainChain.size(); i++)
			{
				if (i <= middle)
					leftChain.push_back(mainChain[i]);
				else
					rightChain.push_back(mainChain[i]);
			}

			unsigned int i = 0;
			unsigned int j = 0;
			Container<unsigned int> mergedChain;
			while (i < leftSize && j < rightSize)
			{
				if (leftChain[i] <= rightChain[j])
				{
					mergedChain.push_back(leftChain[i]);
					i++;
				}
				else
				{
					mergedChain.push_back(rightChain[j]);
					j++;
				}
			}
			while(j < rightSize) //start from right size
			{
				mergedChain.push_back(rightChain[j]);
				j++;
			}
			while(i < leftSize)
			{
				mergedChain.push_back(leftChain[i]);
				i++;
			}
			std::cout << "mergedChain::atomic_commi t " << std::endl;
			PmergeMe::printContainer(mergedChain);
			return mergedChain;
		}

		template <template <typename...> class Container>
		static Container<unsigned int> sortMainChain(Container<unsigned int> &mainChain, unsigned int start, unsigned int end)
		{
			Container<unsigned int> temp;
			if (start >= end) // base case
				return temp;
			unsigned int middle = (start + (end - start)) / 2; // find midpoint
			sortMainChain(mainChain, start, middle); // sort left side, to the left of the midpoint
			sortMainChain(mainChain, middle + 1, end); // sort right side, to the right of the midpoint
			temp= merge(mainChain, start, middle, end);
			return temp;
		}

		template <template <typename...> class Container>
		static void mergeInsertionSort(const Container<unsigned int> &container)
		{
			std::cout << "container at the start" << std::endl;
			PmergeMe::printContainer(container);
			//check first if has even or odd amout of numbers
			unsigned int loner = 0;
			if (container.size() % 2 != 0)
				loner = container.back();
			Container <unsigned int> aChain; // main chain, holds bigger numers (it.firsts)
			Container <unsigned int> bChain; // side chain, holds smaller numbers (it.seconds)
			Container <std::pair<unsigned int, unsigned int>> pairContainer;
			for (unsigned int i = 0; i < container.size() - 1; i = i + 2) // we do not want to iterate to the end, since we always check + 1
			{
				pairContainer.push_back(std::make_pair(container[i], container[i+1]));
				std::cout << "i: " <<  container[i] << ", i + 1: " << container[i+1] << std::endl;
			}

			for (typename Container <std::pair<unsigned int, unsigned int>>::iterator it = pairContainer.begin(); it != pairContainer.end(); it++)
			{
				std::cout << "pushing " << it->first << " and " << it->second << std::endl;
				if (it->first < it->second) // will I benefit from this switcharoo at all? should I just push to the two different chains straight up? depending on the size which container you push it to
				{
					aChain.push_back(it->second); // after sorting holds all the big numbers of the pairs
					bChain.push_back(it->first); // holds all the small numbers of the chains
				}
				else
				{
					aChain.push_back(it->first); // if first is bigger, push it to the main chain
					bChain.push_back(it->second);
				}
			}
			if (loner != 0)
				bChain.push_back(loner);
			std::cout << "before merge insertion" << std::endl;
			PmergeMe::printContainer(aChain);
			Container<unsigned int> presorted = PmergeMe::sortMainChain(aChain, 0, aChain.size() - 1); //recursively sort a Chain by max value
			// binary search sort for the bChain
			std::cout << "from merge insertion" << std::endl;
			PmergeMe::printContainer(presorted);
		}



		template <template <typename...> class Container>
		static Container<unsigned int> validateInputCreateContainer(int argc, char **argv)
		{
			Container<unsigned int> holder;

			for (int i = 1; i < argc; i++)
			{
					unsigned int number = std::stoi(argv[i]);
					if (number >= 0)
						holder.push_back(number);
					else
						throw std::logic_error("allowed only digits as input");
			}

			return holder;
		}

		// template <template <typename...> class Container>
		// static void mergeInsertionSort(const Container<int> &container)
		// {
		// 		Container<std::pair<int, int>> pairs;

		// };

};
