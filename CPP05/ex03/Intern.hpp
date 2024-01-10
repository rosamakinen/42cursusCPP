#pragma once

#include "AForm.hpp"

class Intern
{

	public:
		Intern();
		~Intern();
		Intern(Intern const &another);
		Intern &operator=(Intern const &another);

		AForm *MakeForm(std::string formName, std::string formTarget);

};
