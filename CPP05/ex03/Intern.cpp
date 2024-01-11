#include "Intern.hpp"

Intern::Intern()
{
	//std::cout << "Intern default constructor" << std::endl;
}

Intern::~Intern()
{
	//std::cout << "Intern deconstructor" << std::endl;
}

Intern::Intern(Intern const &another)
{
	//std::cout << "Intern copy constructor" << std::endl;
	(void)another;
}

Intern &Intern::operator=(Intern const &another)
{
	//std::cout << "Intern copy assignment operator" << std::endl;
	(void)another;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	typedef AForm *(Intern::*forms)(std::string target);

	std::string array[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	forms formArray[] = {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePresidentialForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == array[i])
		{
			std::cout << "Intern created " << formName << std::endl;
			 return (this->*formArray[i])(formTarget);
		}
	}
	std::cout << "Intern failed to create  " << formName << std::endl;

	return nullptr;
}

AForm *Intern::makeShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makePresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}
