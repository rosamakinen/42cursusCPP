#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanB
{
	private:

	std::string p_name;
	Weapon *p_weapon;

	public:

	HumanB(std::string name);
	~HumanB(void);
	void	setName(std::string name);
	std::string getName();
	void	setWeapon(Weapon &weapon);
	void	attack();
};



#endif