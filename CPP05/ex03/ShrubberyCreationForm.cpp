#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm parameterized constructor" << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm deconstructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &another) : AForm(another)
{
	*this = another;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &another)
{
	this->_target = another._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignedStatus() == true)
	{
		if (executor.getGrade() <= this->getGradeExec())
		{
			std::cout << executor.getName() << " executed " << this->getName() << std::endl;
			std::ofstream file;
			file.open(this->_filename);

			if (!file)
			{
				throw FileError();
			}
			else
			{
				file << "# # # # # #\n| | | | | |\n";
				file.close();
			}
		}
		else
			throw GradeTooLowException();

	}
	else
		throw NotSigned();
}
