#include "Animal.hpp"

Animal::Animal(std::string type): type(type)
{
	std::cout << "[Animal] " << std::endl;
}

Animal::~Animal()
{

}

std::string Animal::getType()
{
	return this->type;
}

void Animal::makeSound()
{
	std::cout << "nonono" << std::endl;
}