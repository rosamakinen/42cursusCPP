#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <iostream>
#include "AMateria.hpp"

class Floor 
{
	private:
		AMateria *floor[20];

	public:
		Floor();
		Floor(const Floor &another);
		Floor &operator=(const Floor &another);
		~Floor();

		void drop(AMateria *m);
};

#endif