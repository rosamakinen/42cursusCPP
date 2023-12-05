#include <iostream>
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap frag("Frag1");

	frag.highFivesGuys();
	std::cout << "frag hitpoints are: " << frag.getHitPoints() << std::endl;

	return 0;
}
