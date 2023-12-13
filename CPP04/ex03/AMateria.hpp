#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
		AMateria();
		AMateria(std::string const &type);

	public:
		virtual ~AMateria();
		AMateria(const AMateria &another);
		AMateria &operator=(const AMateria &another);

		std::string const 	&getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

#endif
