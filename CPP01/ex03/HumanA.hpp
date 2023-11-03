#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	private:

	std::string p_name;
	Weapon p_weapon;

	public:

	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void	setName(std::string name);
	std::string getName(void);
	void	attack();
};

#endif