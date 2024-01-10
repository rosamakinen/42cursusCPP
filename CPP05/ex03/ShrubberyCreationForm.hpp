#pragma once

#include "AForm.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		std::string _filename = "ShrubberyFile.txt";
		ShrubberyCreationForm();

	public:
		ShrubberyCreationForm(std::string type);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &another);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &another);

		void		execute(Bureaucrat const &executor) const override;
};
