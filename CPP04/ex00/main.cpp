#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* doggie = new Dog();
	const Animal* cattie = new Cat();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "type:  " << cattie->getType() << " " << std::endl;
	cattie->makeSound(); //will output the cat sound!

	std::cout << "type:  " << doggie->getType() << " " << std::endl;
	doggie->makeSound();

	std::cout << "type:  " << meta->getType() << " " << std::endl;
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "type:  " << wrongCat->getType() << " " << std::endl;
	std::cout << "Wrong Cat says ";
	wrongCat->makeSound();
	std::cout << std::endl;
	
	delete cattie;
	delete doggie;
	delete meta;
	delete wrongCat;

	return 0;

}