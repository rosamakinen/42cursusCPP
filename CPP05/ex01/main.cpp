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

		std::cout << "***********************************" << std::endl;
		try
		{
			Bureaucrat	a("jormali", 148);
			Form		form("2222", 9, 5);

			std::cout << std::endl;
			std::cout << a << std::endl;
			std::cout << form << std::endl;
			a.increment();
			a.decrement();
			a.decrement();
			a.signForm(form);
			std::cout << std::endl;
			std::cout << form << std::endl;

		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "***********************************" << std::endl;
	}
		{
		try
		{
			Bureaucrat	b("kalevi", 7);
			Form		form("B3601", 6, 3);

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << form << std::endl;
			b.decrement();
			b.increment();
			b.increment();
			b.signForm(form);
			b.signForm(form);
			std::cout << std::endl;
			std::cout << form << std::endl;

		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "***********************************" << std::endl;
	}
	return 0;
}
