#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "--- Array Test ---" << std::endl;
	const Animal* animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();

	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << "--- Deep Copy Test ---" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}
