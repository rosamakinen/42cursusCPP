#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
		Animal();
		Animal(const Animal &another);

	public:
		virtual ~Animal();
		Animal &operator=(const Animal &another);

		virtual void	makeSound() const;
		std::string getType() const;

};

#endif
