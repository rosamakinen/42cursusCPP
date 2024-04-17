#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <string>
#include <utility>
#include <iterator>

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
			while(j < rightSize) //start from right side
			{
				mergedChain.push_back(rightChain[j]);
				j++;
			}
			while(i < leftSize)
			{
				mergedChain.push_back(leftChain[i]);
				i++;
			}
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
			temp = merge(mainChain, start, middle, end);
			return temp;
		}

		template <template <typename...> class Container>
		static Container<unsigned int> insertionSort(Container<unsigned int> &preSorted, Container<unsigned int> bChain)
		{
			std::cout << "from merge insertion, preSorted: " << std::endl;
			PmergeMe::printContainer(preSorted);
			
			unsigned int key;

			for (unsigned int i = 0; i < bChain.size(); i++) 
			{
				key = bChain[i];
				std::cout << "key: " << key << std::endl;

			    unsigned int size = preSorted.size();
				std::cout << "size: " << size << std::endl;
				if (key < preSorted[0])
				{
					preSorted.insert(preSorted.begin(), key);
					break;
				}
				for (unsigned int j = size - 2; j >= 0; j--) // take into account the dirst element?
				{
					if (preSorted[j] < key && preSorted[j + 1] > key)
					{
						std::cout << "looping: key is: " << key << " j & j + 1 : " << preSorted[j] << ", " << preSorted[j + 1] << std::endl;
						//typename Container<unsigned int>::iterator it = preSorted.begin();
						preSorted.insert(preSorted.begin() + j + 1, key);
						break;
					}
				}
    		}
			std::cout << "should be sorted que? " << std::endl;
			PmergeMe::printContainer(preSorted);
			return preSorted;
		}

		template <template <typename...> class Container>
		static void mergeInsertionSort(const Container<unsigned int> &container)
		{				
			Container <unsigned int> aChain; // main chain, holds bigger numers (it.firsts)
			Container <unsigned int> bChain; // side chain, holds smaller numbers (it.seconds)
			Container <std::pair<unsigned int, unsigned int>> pairContainer;
			for (unsigned int i = 0; i < container.size() - 1; i = i + 2) // we do not want to iterate to the end, since we always check + 1
			{
				pairContainer.push_back(std::make_pair(container[i], container[i+1]));
				std::cout << " " <<  container[i] << " & " << container[i+1] << std::endl;
			}

			for (typename Container <std::pair<unsigned int, unsigned int>>::iterator it = pairContainer.begin(); it != pairContainer.end(); it++)
			{

				if (it->first < it->second) 
				{
					aChain.push_back(it->second);
					bChain.push_back(it->first);
				}
				else
				{
					aChain.push_back(it->first);
					bChain.push_back(it->second);
				}
			}

			if (container.size() % 2 != 0)
				bChain.push_back(container.back());

			std::cout << "before merge insertion" << std::endl;
			PmergeMe::printContainer(aChain);
			Container<unsigned int> preSorted = PmergeMe::sortMainChain(aChain, 0, aChain.size() - 1); //recursively sort a Chain by max value
			Container<unsigned int> sorted = PmergeMe::insertionSort(preSorted, bChain);
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