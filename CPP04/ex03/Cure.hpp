#ifndef CUREMATERIA_HPP
#define CUREMATERIA_HPP

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		std::string name;

	public:
		Cure();
		~Cure();
		Cure(const Cure &another);
		Cure &operator=(const Cure &another);

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);

};

#endif

#endif
