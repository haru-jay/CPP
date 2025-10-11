#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap playerA("bob");
	ScavTrap playerB("ao");

	playerB.attack("bob");
	playerA.takeDamage(playerB.getAttackDamage());
	std::cout << playerA.getHitPoint() <<std::endl;
}