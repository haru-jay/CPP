#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "[AAnimal] Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& rhs)
{
	std::cout << "[AAnimal] Copy constructor called" << std::endl;
	*this = rhs;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	std::cout << "[AAnimal] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal] Destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}
