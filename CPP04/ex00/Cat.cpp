#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat is destructed" << std::endl;
}

Cat::Cat(const Cat &another)
{
	*this = another;
}

Cat &Cat::operator=(const Cat &another)
{
	this->type = another.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat says meow meow" << std::endl;
}