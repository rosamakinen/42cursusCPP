#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>
#include <deque>
#include <iostream>
#include <exception>

class PmergeMe
{

	public:
		template <template <typename...> class Container>
		static void printContainer(const Container<int> &container);

		// template <template <typename...> class Container>
		// static void mergeInsertionSort(const Container<int> &container);





};

#include "./PmergeMe.tpp"

#endif
