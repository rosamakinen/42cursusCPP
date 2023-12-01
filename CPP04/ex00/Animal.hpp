#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected: 
		std::string type;

	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &another);
		Animal &operator=(const Animal &another);

		virtual void	makeSound() const;
		std::string getType() const;

};

#endif