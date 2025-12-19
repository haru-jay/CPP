#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): \
	ClapTrap(name+"_clap_name"), FragTrap(), ScavTrap(), name(name)
{
	this->setHitPoint(FragTrap::getHitPoint());
	this->setEnergyPoint(ScavTrap::getEnergyPoint());
	this->setAttackDamage(FragTrap::getAttackDamage());

	std::cout << "[DiamondTrap] constructor Activate" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), FragTrap(copy), ScavTrap(copy), name(copy.name)
{
	std::cout << "[DiamondTrap] Copy Constructor called" << std::endl;
}

DiamondTrap DiamondTrap::operator=(const DiamondTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
		this->name = rhs.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] destructor Activate" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	if (this->getEnergyPoint() < 1)
	{
		std::cout << "[ " << this->getName() << " ] " << "not enough energy" << std::endl;
		return ;
	}
	std::cout << "[DiamondTrap] " << this->getName() << " attacks " << target << ", causing " << \
	this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoint(this->getEnergyPoint() - 1);
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] name is " << this->name << std::endl;
	std::cout << "[DiamondTrap] ClapTrap name is " << this->getName() << std::endl;
}