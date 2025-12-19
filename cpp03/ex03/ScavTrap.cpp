# include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("", 100, 50, 20)
{
	std::cout << "[ScavTrap] constructor Activate" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "[ScavTrap] constructor Activate" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "[ScavTrap] Copy Constructor called" << std::endl;
	*this = copy;
}

ScavTrap ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this != &rhs)
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] destructor Activate" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getEnergyPoint() < 1)
	{
		std::cout << "[ " << this->getName() << " ] " << "not enough energy" << std::endl;
		return ;
	}
	std::cout << "[ScavTrap] " << this->getName() << " attacks " << target << ", causing " << \
	this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoint(this->getEnergyPoint() - 1);
}

void ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] guardGate Activate" << std::endl;
}