#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* iceKing = new Character("iceKing");
	AMateria* temp;

	temp = src->createMateria("blah");
	temp = src->createMateria("ice");
	iceKing->equip(temp);
	iceKing->equip(temp);
	temp = src->createMateria("cure");
	iceKing->equip(temp);
	iceKing->equip(temp);
	iceKing->unequip(1);
	iceKing->unequip(4);
	temp = src->createMateria("ice");
	iceKing->equip(temp);
	temp = src->createMateria("cure");
	iceKing->equip(temp);
	temp = src->createMateria("cure");
	temp = src->createMateria("cure");
	iceKing->unequip(0);
	iceKing->equip(temp);
	
	ICharacter* pb = new Character("princessBubblegum");
	iceKing->use(0, *pb);
	iceKing->use(5, *pb);
	iceKing->use(2, *pb);

	delete pb;
	delete iceKing;
	delete src;
	return 0;
}
