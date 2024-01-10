#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	{
		try
		{
			Bureaucrat					b("kalevi-b", 5);
			Bureaucrat					c("kalevi-c", 72);
			Bureaucrat					d("kalevi-d", 147);
			ShrubberyCreationForm		shrubbery("kalevi1");
			RobotomyRequestForm			robotomy("kalevi2");
			PresidentialPardonForm		pardon("kalevi3");

			std::cout << std::endl;
			std::cout << b << std::endl;
			std::cout << c << std::endl;
			std::cout << d << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;

			d.signForm(shrubbery);
			c.executeForm(shrubbery);
			std::cout << std::endl;
			std::cout << shrubbery << std::endl;

			c.signForm(robotomy);
			b.executeForm(robotomy);
			std::cout << std::endl;
			std::cout << robotomy << std::endl;

			c.signForm(pardon);
			c.executeForm(pardon);
			b.signForm(pardon);
			b.executeForm(pardon);
			std::cout << std::endl;
			std::cout << pardon << std::endl;

			c.signForm(shrubbery);
			b.executeForm(shrubbery);
			std::cout << std::endl;
			std::cout << robotomy << std::endl;

		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "***********************************" << std::endl;
	}
	return 0;
}
