#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor" << std::endl;
}

Brain::Brain(const Brain &another)
{
	std::cout << "Brain copy constructor" << std::endl;
	*this = another;
}

Brain &Brain::operator=(const Brain &another)
{
	std::cout << "Brain copy assignment operator" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = another.ideas[i];

	return *this;
}

void Brain::setIdea(int index, std::string idea)
{
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
	return this->ideas[index];
}
