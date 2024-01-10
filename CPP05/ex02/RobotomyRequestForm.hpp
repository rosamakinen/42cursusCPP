#pragma once

#include "AForm.hpp"
#include <random>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();

	public:
		RobotomyRequestForm(std::string type);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &another);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &another);

		void	execute(Bureaucrat const &executor) const override;
};
