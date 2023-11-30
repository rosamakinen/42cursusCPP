#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap scav("Scav1");

	scav.attack("Clap2");
	scav.takeDamage(10);
	std::cout << "scavtrap took 10 damage and hitpoints are: " << scav.getHitPoints() << std::endl;
	scav.guardGate();

	return 0;
}