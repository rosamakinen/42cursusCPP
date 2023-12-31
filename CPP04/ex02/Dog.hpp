#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog &another);
		Dog &operator=(const Dog &another);

		void	makeSound() const;
		Brain &getBrain();
};

#endif