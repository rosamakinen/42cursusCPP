#include "iter.hpp"

template<typename T>
void print(T printable)
{
	std::cout << printable << std::endl;
}

int main( void ) 
{
	int intArray[] = {0, 1, 2, 3, 4};
	std::string strArray[] = {"zero", "one", "two", "three", "four"};

	iter(intArray, 5, print);
	iter(strArray, 5, print);

	return 0;
}