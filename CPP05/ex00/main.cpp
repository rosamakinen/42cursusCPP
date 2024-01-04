#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	{
		try
		{
			Bureaucrat x("perttuli", 151);
			Bureaucrat y("jalmari", 0);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Bureaucrat a("jormali", 148);

			std::cout << std::endl;
			std::cout << a << std::endl;
			a.increment();
			a.decrement();
			a.decrement();
			a.decrement();
			a.decrement();

		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
		{
		try
		{
			Bureaucrat b("kalevi", 2);

			std::cout << std::endl;
			std::cout << b << std::endl;
			b.decrement();
			b.increment();
			b.increment();
			b.increment();
			b.increment();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
