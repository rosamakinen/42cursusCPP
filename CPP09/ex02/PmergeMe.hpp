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
			for (const auto& it : container)
			{
				std::cout << it << std::endl;
			}
		};

		template <template <typename...> class Container>
		static void mergeInsertionSort(const Container<unsigned int> &container)
		{
			Container <std::pair<unsigned int, unsigned int>> pairContainer;
			for (int i = 0; i < container.size/2; i = i + 2)
			{
				pairContainer.push_back(std::make_pair(i, i+1));
			}

		};

		// template <template <typename...> class Container>
		// static void mergeInsertionSort(const Container<int> &container)
		// {
		// 		Container<std::pair<int, int>> pairs;

		// };

};
