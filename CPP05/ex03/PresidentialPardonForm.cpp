#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm parameterized constructor" << std::endl;
	this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &another) : AForm(another)
{
	*this = another;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &another)
{
	this->_target = another._target;
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == true)
	{
		if (executor.getGrade() <= this->getGradeExec())
		{
			std::cout << executor.getName() << " executed " << this->getName() << std::endl;
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw NotSigned();
}
