#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string 	_name;
		int					_grade;
		Bureaucrat();

	public:
		Bureaucrat(std::string input, int inputGrade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &another);
		Bureaucrat &operator=(const Bureaucrat &another);

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

		void	increment();
		void	decrement();

		std::string	getName() const;
		int			getGrade() const;

};
		std::ostream&	operator<<(std::ostream& os, const Bureaucrat &bur);
