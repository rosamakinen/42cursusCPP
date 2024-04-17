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
		static void merge(Container<unsigned int> &mainChain, unsigned int start, unsigned int middle, unsigned int end)
		{
			unsigned int leftSize = middle - start + 1;
			unsigned int rightSize = end - middle;

			Container<unsigned int> rightChain(rightSize);
			Container<unsigned int> leftChain(leftSize);
			for (unsigned int i = 0; i < leftSize; i++)
			{
				leftChain[i] = mainChain[i + start];
			}

			for (unsigned int j = 0; j < rightSize; j++)
			{
				rightChain[j] = mainChain[middle + j + 1];
			}
			unsigned int i = 0;
			unsigned int j = 0;
			unsigned int k = start;
	
			while (i < leftSize && j < rightSize)
			{
				if (leftChain[i] <= rightChain[j])
				{    
					mainChain[k] = leftChain[i];
					i++;
				}
				else
				{
					mainChain[k] = rightChain[j];
					j++;
				}
				k++;
			}

			while(i < leftSize)
			{
				mainChain[k] = leftChain[i];
				i++;
				k++;
			}
			while(j < rightSize)
			{
				mainChain[k] = rightChain[j];
				j++;
				k++;
			}
			std::cout << "after a round of sorting " << std::endl;
			PmergeMe::printContainer(mainChain);
		}

		template <template <typename...> class Container>
		static void sortMainChain(Container<unsigned int> &mainChain, unsigned int start, unsigned int end)
		{
			Container<unsigned int> temp;
			unsigned int middle = start + (end - start) / 2;
			std::cout << "start: " << start << " middle: " << middle << " end: " << end << std::endl;
			if (start >= end || middle == end)
				return;
			
			sortMainChain(mainChain, start, middle);
			sortMainChain(mainChain, middle + 1, end);
			merge(mainChain, start, middle, end);
			return;
		}

		template <template <typename...> class Container>
		static Container<unsigned int> insertionSort(Container<unsigned int> &preSorted, Container<unsigned int> bChain)
		{
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
					continue;
				}
				for (unsigned int j = size - 2; j >= 0; j--)
				{
					if (preSorted[j] < key && preSorted[j + 1] > key)
					{
						std::cout << "looping: key is: " << key << " j & j + 1 : " << preSorted[j] << ", " << preSorted[j + 1] << std::endl;
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

			PmergeMe::sortMainChain(aChain, 0, aChain.size() - 1); //recursively sort a Chain by max value
			Container<unsigned int> sorted = PmergeMe::insertionSort(aChain, bChain);
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