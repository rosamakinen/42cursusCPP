#include <iostream>

class	ClapTrap
{
	private:
		std::string	name;
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;


	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &another);
		~ClapTrap();
		ClapTrap operator=(ClapTrap &another);

};
