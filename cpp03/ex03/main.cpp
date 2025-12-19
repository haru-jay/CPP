#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap playerD("dia");
	playerD.whoAmI();

	ClapTrap playerA("bob");
	playerD.attack("bob");
	playerA.takeDamage(playerD.getAttackDamage());
	std::cout << playerA.getHitPoint() <<std::endl;
	return 0;
}