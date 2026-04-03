#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "[Animal] Default constructor called" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
	std::cout << "[Animal] Copy constructor called" << std::endl;
	*this = rhs;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "[Animal] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "[Animal] Some generic animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}
