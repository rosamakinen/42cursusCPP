#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:
		AForm *makeShrubberyForm(std::string target);
		AForm *makePresidentialForm(std::string target);
		AForm *makeRobotomyForm(std::string target);


	public:
		Intern();
		~Intern();
		Intern(Intern const &another);
		Intern &operator=(Intern const &another);

		AForm *makeForm(std::string formName, std::string formTarget);
};
