#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource defaut constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materias[i] = nullptr;
			
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource deconstructor" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->materias[i];
}

MateriaSource::MateriaSource(const MateriaSource &another)
{
	std::cout << "MateriaSource copyconstructor" << std::endl;
	*this = another;

}

MateriaSource &MateriaSource::operator=(const MateriaSource &another)
{
	std::cout << "MateriaSource copy assignment operator" << std::endl;
	if (this != &another)
	{
		for (int i = 0; i < 4; i++)
			delete this->materias[i];
		for (int i = 0; i < 4; i++)
			this->materias[i] = another.materias[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (this->materias[i] == nullptr)
		{
			this->materias[i] = m;
			std::cout << "YAY, learned a new materia!" << std::endl;
		}
	std::cout << "Oh, sorry, we have learned all we can" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++){
		if ((this->materias[i] != nullptr) && (this->materias[i]->getType() == type)) {
			AMateria *tempMateria = this->materias[i]->clone();
			std::cout << "YAY, created a new materia" << std::endl;
			return tempMateria;
		}
	}
	std::cout << "Sorry, cannot create a materia we don't recognize" << std::endl;
	return nullptr;
}
