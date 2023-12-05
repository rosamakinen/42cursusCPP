#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(ScavTrap &another);

		ScavTrap &operator=(ScavTrap &another);

		void	attack(const std::string &target);
		void	guardGate();

		int		getHitPoints();
} ;