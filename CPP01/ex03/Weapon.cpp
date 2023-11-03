#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
	this->p_type = name;
}
Weapon::~Weapon()
{

}

void	Weapon::setType(std::string type)
{
	this->p_type = type;
}

const std::string& Weapon::getType() const
{
	return this->p_type;
}