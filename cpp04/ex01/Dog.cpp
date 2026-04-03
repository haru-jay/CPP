#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "[Dog] Default constructor called" << std::endl;
}

Dog::Dog(const Dog& rhs) : Animal(rhs)
{
	std::cout << "[Dog] Copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = rhs;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "[Dog] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->type = rhs.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "[Dog] Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return this->brain;
}
