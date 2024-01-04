#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
	//std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string input, int inputGrade) : _name(input), _grade(inputGrade)
{
	//std::cout << "Bureaucrat parameterized constructor" << std::endl;
	if (this->_grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (this->_grade > 150)
	{
		throw GradeTooLowException();
	}
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat deconstructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &another) : _name(another._name), _grade(another._grade)
{
	//std::cout << "Bureaucrat copy constructor" << std::endl;
	if (this->_grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (this->_grade > 150)
	{
		throw GradeTooLowException();
	}
	*this = another;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &another)
{
	//std::cout << "Bureaucrat copy assignment operator" << std::endl;
	if (this->_grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (this->_grade > 150)
	{
		throw GradeTooLowException();
	}
	this->_grade = another._grade;
	return *this;
}

// 1 highest, 150 lowest. incrementing 3 is 2
void	Bureaucrat::increment()
{
	if (this->_grade <= 1)
	{
		throw GradeTooHighException();
	}
	this->_grade--;
	std::cout << this->getName() << " grade incremented to "  << this->getGrade() << std::endl;
}

// 1 highest, 150 lowest. decrementing 3 is 4
void	Bureaucrat::decrement()
{
	if (this->_grade >= 150)
	{
		throw GradeTooLowException();
	}
	this->_grade++;
	std::cout << this->getName() << " grade decremented to " << this->getGrade() << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur)
{
	os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << "." << std::endl;

	return os;
}

void Bureaucrat::signForm(Form &frm) const
{
	try
	{
		frm.beSigned(*this);
		std::cout << this->getName() << " signed " << frm.getName() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << frm.getName()
		<< " because '" << e.what() << "'." << std::endl;
	}
}
