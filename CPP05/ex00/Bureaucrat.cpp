#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(0)
{
	//std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string input, int inputGrade) : _name(input), _grade(inputGrade)
{
	//std::cout << "Bureaucrat parameterized constructor" << std::endl;
	if (_grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (_grade > 150)
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
	if (_grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (_grade > 150)
	{
		throw GradeTooLowException();
	}
	*this = another;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &another)
{
	//std::cout << "Bureaucrat copy assignment operator" << std::endl;
	if (_grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (_grade > 150)
	{
		throw GradeTooLowException();
	}
	this->_grade = another._grade;
	return *this;
}

std::string Bureaucrat::getName()
{
	return this->_name;
}

int Bureaucrat::getGrade()
{
	return this->_grade;
}
