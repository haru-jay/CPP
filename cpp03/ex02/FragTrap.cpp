# include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("", 100, 100, 30)
{
	std::cout << "[FragTrap] constructor Activate" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "[FragTrap] constructor Activate" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "[FragTrap] Copy Constructor called" << std::endl;
	*this = copy;
}

FragTrap FragTrap::operator=(const FragTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] destructor Activate" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "[FragTrap] highFivesGuys" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (this->getEnergyPoint() < 1)
	{
		std::cout << "[ " << this->getName() << " ] " << "not enough energy" << std::endl;
		return ;
	}
	std::cout << "[FragTrap] " << this->getName() << " attacks " << target << ", causing " << \
	this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoint(this->getEnergyPoint() - 1);
}