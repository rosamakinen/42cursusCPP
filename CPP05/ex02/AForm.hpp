#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string 	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;
		AForm();

	public:
		AForm(std::string name, int gradeToSign, int gradeToExec);
		~AForm();
		AForm(AForm const &another);
		AForm &operator=(AForm const &another);

		class GradeTooHighException : public std::runtime_error
		{
			public:
				GradeTooHighException() : std::runtime_error("Sorry pal, grade too high") {};
		};

		class GradeTooLowException : public std::runtime_error
		{
			public:
				GradeTooLowException() : std::runtime_error("Sorry pal, grade too low") {};
		};

		class AlreadySigned : public std::runtime_error
		{
			public:
				AlreadySigned() : std::runtime_error("Sorry pal, the form was already signed") {};
		};

		int			getGradeSign() const;
		int			getGradeExec() const;
		bool		getSignedStatus() const;
		std::string	getName() const;
		void		beSigned(const Bureaucrat &bur);
};

std::ostream &operator<<(std::ostream &os, AForm const &frm);
