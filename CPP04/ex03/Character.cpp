#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = nullptr;
	floor = new Floor();
}

Character::Character(std::string name) : name(name)
{
	std::cout << "Character name constructor" << std::endl;
}

Character::Character(const Character &another)
{
	std::cout << "Character copy constructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->inventory[i] = another.inventory[i];
	}
	floor = new Floor();
	this->name = another.getName();
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->inventory[i] != nullptr)
		{
			delete this->inventory[i];
			this->inventory[i] = nullptr;
		}
	delete floor;
}

Character Character::operator=(const Character &another)
{
	std::cout << "Character copy assignment operator" << std::endl;
	if (this != &another)
	{
		this->name = another.name;
		for (int i = 0; i < 4; i++)
			if (this->inventory[i] != nullptr)
			{
				delete this->inventory[i];
				this->inventory[i] = nullptr;
			}
		for (int i = 0; i < 4; i++)
			this->inventory[i] = another.inventory[i];
		floor = another.floor;
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
	if (idx >= 0 && idx < 4)
	{
		if (this->inventory[idx] == nullptr)
		{
			std::cout << "nothing in the slot" << std::endl;
			return ;
		}
		else
		{
			this->floor->drop(inventory[idx]);
			this->inventory[idx] = nullptr;
			return;
		}
	}
	std::cout << "Hi pal, you can't reach there" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && idx >= 0)
	{
		if (this->inventory[idx] != nullptr)
		{
			this->inventory[idx]->use(target);
			return ;
		}
		else
		{
			std::cout << "nothing in the slot" << std::endl;
		}	
	}
		return;
}
