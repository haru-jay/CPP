#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "[WrongCat] Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
	std::cout << "[WrongCat] Copy constructor called" << std::endl;
	*this = rhs;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "[WrongCat] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] Wrong Meow! Meow!" << std::endl;
}
