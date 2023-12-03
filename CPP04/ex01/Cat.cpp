#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "Cat constructor" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat is destructed" << std::endl;
}

Cat::Cat(const Cat &another)
{
	std::cout << "Cat copy operator" << std::endl;
	this->type = another.type;
	this->brain = new Brain(*another.brain);
}

Cat &Cat::operator=(const Cat &another)
{
	std::cout << "Cat copy assignment operator" << std::endl;
	this->type = another.type;
	delete brain;
	this->brain = new Brain(*another.brain);

	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat says meow meow" << std::endl;
}

Brain &Cat::getBrain()
{
	return *this->brain;
}