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

RobotomyRequestForm::RobotomyRequestForm(AForm const &another) : AForm(another)
{

}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == true && executor.getGrade() >= this->getGradeExec())
	{
		if (rand() % 2 == 0)
			std::cout << this->_target << " has been robotomized succesfully" << std::endl;
		else
			std::cout << "failed to robotomize " << this->_target << std::endl;
	}
}
