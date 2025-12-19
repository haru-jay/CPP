#include "ClapTrap.hpp"

int main()
{
	ClapTrap playerA("bob"), playerB("AO");

	playerA.attack("AO");
	playerB.takeDamage(playerA.getAttackDamage());
	std::cout <<  playerA.getEnergyPoint() <<std::endl;
	std::cout <<  playerB.getHitPoint() <<std::endl;
	return 0;
}