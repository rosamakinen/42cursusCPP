#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
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
			std::cout << std::endl;

			Intern e;
			AForm *shrubbers = e.makeForm("ShrubberyCreationForm", "uolevi");
			AForm *pardonss = e.makeForm("PresidentialPardonForm", "uolevi2");
			AForm *robottoms = e.makeForm("RobotomyRequestForm", "uolevi3");

			std::cout << std::endl;
			d.signForm(*shrubbers);
			std::cout << std::endl;
			b.signForm(*pardonss);
			b.signForm(*robottoms);

			std::cout << std::endl;
			d.executeForm(*shrubbers);
			std::cout << std::endl;
			b.executeForm(*pardonss);
			b.executeForm(*robottoms);

			std::cout << std::endl;
			delete shrubbers;
			delete pardonss;
			delete robottoms;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
