#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include "Animal.hpp"
#include <iostream>

int	main(void)
{
	
	Animal *animals[4];

	for (int i = 0; i < 4; i++)
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();

	for (int i = 0; i < 4; i++)
		delete animals[i];

	Dog theDog;
	theDog.getBrain().setIdea(0, "i really like to sniff stuff");
	std::cout << "the doggi: '" << theDog.getBrain().getIdea(0) << "' " << std::endl;

	// using copy constructor for doggie
	Dog copyDoggie(theDog);
	std::cout << "the doggi: '" << theDog.getBrain().getIdea(0) << "' " << std::endl;
	std::cout << "copy doggi: '" << copyDoggie.getBrain().getIdea(0) << "' " << std::endl;
	theDog.getBrain().setIdea(0, "hau hau hau");
	std::cout << "the doggi: '" << theDog.getBrain().getIdea(0) << "' " << std::endl;
	std::cout << "copy doggi: '" << copyDoggie.getBrain().getIdea(0) << "' " << std::endl;

	// using copy assigning operator for doggie
	Dog copyassignDoggie = theDog;
	std::cout << "the doggi: '" << theDog.getBrain().getIdea(0) << "' " << std::endl;
	std::cout << "copy doggi: '" << copyassignDoggie.getBrain().getIdea(0) << "' " << std::endl;
	theDog.getBrain().setIdea(0, "bark bark bark");
	std::cout << "the doggi: '" << theDog.getBrain().getIdea(0) << "' " << std::endl;
	std::cout << "copy doggi: '" << copyassignDoggie.getBrain().getIdea(0) << "' " << std::endl;

	return 0;

}