#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include "Animal.hpp"
#include <iostream>

int	main(void)
{
	Animal *cat = new Cat;
	// Animal *animal = new Animal;

	delete cat;
	// delete animal;

	return 0;
}
