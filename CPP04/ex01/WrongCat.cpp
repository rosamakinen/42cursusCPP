#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Wrong Cat";
	std::cout << "WrongCat constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is destructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &another)
{
	*this = another;
}

WrongCat &WrongCat::operator=(const WrongCat &another)
{
	this->type = another.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat says heyyyyy what the heck is this" << std::endl;
}