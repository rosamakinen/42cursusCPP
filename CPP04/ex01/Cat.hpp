#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &another);
		Cat &operator=(const Cat &another);

		void	makeSound() const;

};

#endif