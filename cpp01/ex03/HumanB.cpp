#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	wp = NULL;
	human_name = name;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	wp = &weapon;
}

void HumanB::attack()
{
	if (wp != NULL)
		std::cout << human_name << " attacks with their " << wp->getType() << std::endl;
	else
		std::cout << human_name << " attacks with their empty-handed" << std::endl;
}