#pragma once

#include "Aform.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm();
		std::string _target;

	public:
		RobotomyRequestForm(std::string type);
		~RobotomyRequestForm();
		RobotomyRequestForm(AForm const &another);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &another);

		void		execute(Bureaucrat const &executor) const override;
};

std::ostream &operator<<(std::ostream &os, AForm const &frm);
