#include "Zombie.hpp"

int main()
{
	Zombie *zb = zombieHorde(10, "fooo");
	delete[] zb;	
	return 0;
}