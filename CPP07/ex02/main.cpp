#include "Array.hpp"

int main( void ) 
{
	std::cout << "***   TEST FOR SIMPLE TYPES:    ***" << std::endl;
	//tests for simple types
	Array<int> empty;
	Array<int> test1(5);
    Array<int> test2(15);

    for (unsigned int i = 0; i < test1.size(); i++)
        test1[i] = 5;

	// print what's in test1
    try
    {
        for (unsigned int i = 0; i < test1.size(); i++)
			std::cout << "value in [" << i << "] is: " << test1[i] << std::endl;
		std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	empty = test1;
	//proof of copy

    try
    {
        std::cout << "proof of copy in empty: " << empty[1] << std::endl;
        std::cout << "proof of copy in test1: " << test1[1] << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	//set values for test2, to check that the accessor and exeption works
    for (unsigned int i = 0; i < test2.size(); i++)
        test2[i] = i;

	//check contents
	try
    {
        for (unsigned int i = 0; i < test2.size(); i++)
			std::cout << "value in [" << i << "] is: " << test2[i] << std::endl;
		std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //accessing an index
    try
    {
        std::cout << "from array size " << test2.size() << ", get index[5]: " << test2[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

     //accessing an invalid index
    try
    {
        std::cout << "from array size " << test2.size() << ", get index[15]: " << test2[15] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	std::cout << "\n\n***   TEST FOR COMPLEX TYPES:    ***" << std::endl;
    //test for complex types
	Array<std::string> complex(5);
	complex[0] = "zero";
	complex[1] = "one";
	complex[2] = "two";
	complex[3] = "three";
	complex[4] = "four";
   
	// print the complex array
	for (unsigned int i = 0; i < complex.size(); i++)
		std::cout << "complex index [" << i << "] has value: " << complex[i] << std::endl;
	std::cout << std::endl;
	
	// modify value
	complex[3] = "kikkelskokkels";

	// print the complex array to check the change
	for (unsigned int i = 0; i < complex.size(); i++)
		std::cout << "complex index [" << i << "] has value: " << complex[i] << std::endl;
	std::cout << std::endl;
	//accessing an invalid index
    try
    {
        std::cout << "from array size " << complex.size() << ", get index[15]: " << complex[15] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return(0);
}