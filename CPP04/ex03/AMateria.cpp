#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Amateria default constructor" << std::endl;
}
AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "Amateria constructor with parameter" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Amateria destructor" << std::endl;
}

AMateria::AMateria(const AMateria &another)
{
	std::cout << "Amateria copy constructor" << std::endl;
	this->type = another.type;
}

AMateria &AMateria::operator=(const AMateria &another)
{
	std::cout << "Amateria copy assignment operator" << std::endl;
	if (this != &another)
	{
		this->type = another.type; //maybe not needed
	}
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter & target)
{
	if (this->type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	if (this->type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


