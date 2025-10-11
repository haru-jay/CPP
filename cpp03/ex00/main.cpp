#include "ClapTrap.hpp"

int main()
{
	ClapTrap playerA("bob"), playerB("ao");

	playerA.attack("ao");
	playerB.takeDamage(playerA.getAttackDamage());
	std::cout <<  playerA.getEnergyPoint() <<std::endl;
	std::cout <<  playerB.getHitPoint() <<std::endl;
	
}