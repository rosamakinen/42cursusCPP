#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog &another)
{
	std::cout << "Dog copy constructor" << std::endl;
	this->type = another.type;
	this->brain = new Brain (*another.brain);
}

Dog &Dog::operator=(const Dog &another)
{
	std::cout << "Dog copy assignment operator" << std::endl;
	this->type = another.type;
	delete brain;
	this->brain = new Brain (*another.brain);

	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog says woof woof" << std::endl;
}

Brain &Dog::getBrain()
{
	return *this->brain;
}