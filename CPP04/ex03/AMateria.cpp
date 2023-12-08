#include "AMateria.hpp"

AMateria::AMateria()
{
}
AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &another)
{
	this->type = another.type;
}

AMateria &AMateria::operator=(const AMateria &another)
{
	this->type = another.type;
	return this;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(Icharacter & target)
{
}


