#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &another);
		WrongAnimal &operator=(const WrongAnimal &another);

		void	makeSound() const;
		std::string getType() const;

};

#endif
