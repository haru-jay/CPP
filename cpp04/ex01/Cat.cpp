#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "[Cat] Default constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = rhs;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "[Cat] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "[Cat] Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return this->brain;
}
