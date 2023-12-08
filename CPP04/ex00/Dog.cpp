#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog is destructed" << std::endl;
}

Dog::Dog(const Dog &another) : Animal(another)
{
	*this = another;
}

Dog &Dog::operator=(const Dog &another)
{
	this->type = another.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog says woof woof" << std::endl;
}
