#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;

}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap &another) : ClapTrap(another.name)
{
	std::cout << "FragTrap Copy constructor" << std::endl;
	*this = another;
}

FragTrap &FragTrap::operator=(FragTrap &another)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;

	this->name = another.name;
	this->attackDamage = another.attackDamage;
	this->energyPoints = another.energyPoints;
	this->hitPoints = another.hitPoints;

	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "CAAANN I GET A HIIIIIGH FIVE? YESS?" << std::endl;
}

int FragTrap::getHitPoints()
{
	return this->hitPoints;
}
