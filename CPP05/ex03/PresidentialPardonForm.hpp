#pragma once

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string type);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &another);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &another);

		void		execute(Bureaucrat const &executor) const override;
};
