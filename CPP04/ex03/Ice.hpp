#ifndef ICEMATERIA_HPP
#define ICEMATERIA_HPP

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		std::string name;

	public:
		Ice();
		~Ice();
		Ice(const Ice &another);
		Ice &operator=(const Ice &another);

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);

};

#endif
