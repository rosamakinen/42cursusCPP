#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <array>

int main()
{
	std::list<int> list {0,1,2,3,4};
	try
	{
		std::cout << easyfind(list, 0) << std::endl;
		std::cout << easyfind(list, 4) << std::endl;
		std::cout << easyfind(list, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::array<int, 5> array {5,6,7,8,9};
	try
	{
		std::cout << easyfind(array, 5) << std::endl;
		std::cout << easyfind(array, 9) << std::endl;
		std::cout << easyfind(array, 0) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


}