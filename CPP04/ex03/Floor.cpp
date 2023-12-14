#include "Floor.hpp"

Floor::Floor()
{
	std::cout << "Floor default constructor" << std::endl;
	for (int i = 0; i < 20; i++)
		this->floor[i] = nullptr;
}

Floor::Floor(const Floor &another)
{
	std::cout << "Floor copy constructor" << std::endl;
	*this = another;
}

Floor &Floor::operator=(const Floor &another)
{
	std::cout << "Floor copy assignment operator" << std::endl;
	if (this != &another)
	{
			for (int i = 0; i < 4; i++)
				if (this->floor[i] != nullptr)
				{
					delete this->floor[i];
					this->floor[i] = nullptr;
				}
				for (int i = 0; i < 4; i++)
					this->floor[i] = another.floor[i]->clone();
	}
	return *this;
}

Floor::~Floor()
{
	std::cout << "Floor deconstructor" << std::endl;
	for (int i = 0; i < 20; i++)
		if (this->floor[i] != nullptr)
		{
			delete floor[i];
			floor[i] = nullptr;
		}	
}

void Floor::drop(AMateria *m)
{
	for (int i = 0; i < 20; i++)
		if (this->floor[i] == nullptr)
		{
			this->floor[i] = m;
			std::cout << "Whoopsie, you dropped something on the floor" << std::endl;
		}
		std::cout << "Darn it, the floor is full of stuff, now i think it got lost" << std::endl;
		delete m;
}
