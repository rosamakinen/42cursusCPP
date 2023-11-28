#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(10)
{
	std::cout << "ClapTrap constructed" << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(ClapTrap &another)
{
	std::cout << "Copy constructor called"<< std::endl;
	*this = another;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &another)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = another.name;
	this->attackDamage = another.attackDamage;
	this->energyPoints = another.energyPoints;
	this->hitPoints = another.hitPoints;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << this->name << " cannot attack, not enough points" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
	 << this->attackDamage << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{

	this->hitPoints = this->hitPoints - amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << this->name << " cannot repair, not enough points" << std::endl;
		return ;
	}
	this->energyPoints--;
	this->hitPoints = this->hitPoints + amount;
	return ;
}
