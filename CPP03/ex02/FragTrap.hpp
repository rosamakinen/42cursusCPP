#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>


class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap &another);

		FragTrap &operator=(FragTrap &another);

		void	highFivesGuys(void);
		int		getHitPoints();
};

#endif
