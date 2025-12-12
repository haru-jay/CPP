#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon HumanA::defaultWeapon("APPLE");
HumanA::HumanA(std::string name): human_name(name), wp(defaultWeapon){}
HumanA::HumanA(std::string name, Weapon &weapon): human_name(name), wp(weapon){}
HumanA::~HumanA(){}

void HumanA::attack()
{
	std::cout << human_name << " attacks with their " << wp.getType() << std::endl;
}