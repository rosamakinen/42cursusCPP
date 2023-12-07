#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor" << std::endl;
}

Animal::Animal(const Animal &another)
{
	std::cout << "Animal copy constructor" << std::endl;
	*this = another;
}

Animal &Animal::operator=(const Animal &another)
{
	std::cout << "Animal copy assgnment operator" << std::endl;
	this->type = another.type;
	
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "ambiguous animal sounds" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
