#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("animal")
{
	std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &another)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = another;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &another)
{
	std::cout << "WrongAnimal copy assgnment operator" << std::endl;
	this->type = another.type;

	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "ambiguous wronganimal sounds" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}
