#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zb = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zb[i].ZombieName(name);
		zb[i].announce();
	}
	return zb;
}