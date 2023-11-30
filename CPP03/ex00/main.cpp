#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("Clap1");

	clap.attack("Clap2");

	clap.takeDamage(10);
	clap.attack("Clap2");
	std::cout << "claptrap took 10 damage and hitpoints are: " << clap.getHitPoints() << std::endl;

	return 0;
}