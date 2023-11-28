#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("Clap1");

	clap.attack("Clap2");

	clap.takeDamage(10);
	clap.attack("Clap2");
	return 0;
}