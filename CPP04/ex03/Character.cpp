#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor" << std::endl;
}

Character::Character(std::string name) : name(name)
{
	std::cout << "Character name constructor" << std::endl;
}

Character::Character(const Character &another)
{
	std::cout << "Character copy constructor" << std::endl;
	*this = another;
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;

}

Character Character::operator=(const Character &another)
{
	std::cout << "Character copy assignment operator" << std::endl;
	if (this != &another)
	{
		this->name = another.name;
		delete this->inventory;
		for (int i = 0; i < 4; i++)
			this->inventory[i] = another.inventory[i];
	}
	return *this;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == nullptr)
		{
			this->inventory[i] = m;
			std::cout << "materia equipped to slot " << i << std::endl;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
		return;
	if (this->inventory[idx] == nullptr)
	{
		std::cout << "nothing in the slot" << std::endl;
		return ;
	}
	this->inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && idx >= 0 && inventory[idx] != nullptr)
		return;
	this->inventory[idx]->use(target);
}
