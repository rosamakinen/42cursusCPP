#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon
{
	private:

	std::string p_type;

	public:

	Weapon(std::string name);
	~Weapon(void);
	void		setType(std::string type);
	const std::string& getType() const;
};

#endif