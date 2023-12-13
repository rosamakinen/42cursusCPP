#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
	std::cout << "Cure default constructor" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

Cure::Cure(const Cure &another) : AMateria(another)
{
	std::cout << "Cure copy constructor" << std::endl;
	*this = another;
}

Cure &Cure::operator=(const Cure &another)
{
	std::cout << "Cure copy assignment operator" << std::endl;
	if (this != &another)
	{
		this->name = another.name;
	}
	return *this;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target->name << "'s wounds *" << std::endl;
}
