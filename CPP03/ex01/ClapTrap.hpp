#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class	ClapTrap
{
	protected:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;


	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &another);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap &another);
		
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		int		getHitPoints();
};

#endif