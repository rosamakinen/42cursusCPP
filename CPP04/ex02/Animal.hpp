#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		Animal();
		Animal(const Animal &another);
		std::string type;

	public:
		virtual ~Animal();
		Animal &operator=(const Animal &another);

		virtual void	makeSound() const = 0;
		std::string getType() const;

};

#endif
