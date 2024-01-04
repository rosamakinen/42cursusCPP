#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeSign(gradeToSign), _gradeExec(gradeToExec)
{
	//std::cout << "Form parameterized constructor" << std::endl;
	if (this->_gradeSign < 1 || this->_gradeExec < 1)
	{
		throw GradeTooHighException();
	}
	else if (this->_gradeSign > 150 || this->_gradeExec > 150)
	{
		throw GradeTooLowException();
	}
}

Form::~Form()
{
	//std::cout << "Form destructor" << std::endl;
}

Form::Form(Form const &another) : _name(another._name), _signed(false), _gradeSign(another._gradeSign), _gradeExec(another._gradeExec)
{
	if (this->_gradeSign < 1 || this->_gradeExec < 1)
	{
		throw GradeTooHighException();
	}
	else if (this->_gradeSign > 150 || this->_gradeExec > 150)
	{
		throw GradeTooLowException();
	}
	*this = another;
}

Form &Form::operator=(Form const &another)
{
	this->_signed = another._signed;
	return *this;
}

int Form::getGradeSign() const
{
	return this->_gradeSign;
}

int Form::getGradeExec() const
{
	return this->_gradeExec;
}

bool Form::getSignedStatus() const
{
	return this->_signed;
}

std::string Form::getName() const
{
	return this->_name;
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (this->_signed == false)
	{
		if (bur.getGrade() <= this->getGradeSign())
		{
			this->_signed = true;
		}
		else
		{
			throw GradeTooLowException();
		}
	}
	else
		throw AlreadySigned();
}

std::ostream &operator<<(std::ostream &os, Form const &frm)
{
	os << frm.getName() << " form: \n " << "signed: " << frm.getSignedStatus() << " (1 true, 0 false)"
	<<  "\n to sign: " << frm.getGradeSign() << " \n to execute: " << frm.getGradeExec()
	<< std::endl;
	return os;
}
