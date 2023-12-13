#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

Ice::Ice(const Ice &another) : AMateria(another)
{
	std::cout << "Ice copy constructor" << std::endl;
	*this = another;
}

Ice &Ice::operator=(const Ice &another)
{
	std::cout << "Ice copy assignment operator" << std::endl;
	if (this != &another)
	{
		this->name = another.name;
	}
	return *this;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target->name << " *" << std::endl;
}
