#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm parameterized constructor" << std::endl;
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &another) : AForm(another)
{
	*this = another;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &another)
{
	this->_target = another._target;
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == true)
	{
		if (executor.getGrade() <= this->getGradeExec())
		{
			std::cout << executor.getName() << " executed " << this->getName() << std::endl;
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<> distribution(0, 1);
			double random = distribution(gen);
			if (random >= 0.5)
				std::cout << "* zrrrRRr xzrrRrrrrRr zdrrrrlllrr * " << this->_target << " has been robotomized succesfully" << std::endl;
			else
				std::cout << "Oh no, the robotomy was a failure for " << this->_target << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw NotSigned();
}
