#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap playerA("bob");
	ScavTrap playerB("ao");
	FragTrap playerC("Frag");

	playerC.attack("ao");
	playerB.takeDamage(playerC.getAttackDamage());
	std::cout << playerB.getHitPoint() <<std::endl;
	
	playerB.attack("bob");
	playerA.takeDamage(playerB.getAttackDamage());
	std::cout << playerA.getHitPoint() <<std::endl;
	
	playerC.highFivesGuys();
	return 0;
}