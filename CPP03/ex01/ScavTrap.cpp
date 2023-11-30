#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;

}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &another) : ClapTrap(another.name)
{
	std::cout << "ScavTrap Copy constructor" << std::endl;

	*this = another;
}

ScavTrap &ScavTrap::operator=(ScavTrap &another)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;

	this->name = another.name;
	this->attackDamage = another.attackDamage;
	this->energyPoints = another.energyPoints;
	this->hitPoints = another.hitPoints;

	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << this->name << " cannot attack, not enough points" << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "
	 << this->attackDamage << " points of damage!" << std::endl;

	return ;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
	return ;
}

int	ScavTrap::getHitPoints()
{
	return this->hitPoints;
}