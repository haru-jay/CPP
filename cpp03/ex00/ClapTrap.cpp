#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), hit_point(10), energy_points(10), attack_damage(0)
{
	std::cout << "constructor Activate" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor Activate" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& rhs){(void)rhs;}
ClapTrap ClapTrap::operator=(const ClapTrap& rhs){return rhs;}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hit_point -= (int)amount;
	if (hit_point < 1)
	{
		std::cout << "[ " << this->name << " ] " << "is died" << std::endl;
	}
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_points < 1)
	{
		std::cout << "[ " << this->name << " ] " << "not enough energy" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << \
	this->attack_damage << " points of damage!" << std::endl;
	this->energy_points--;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points < 1)
	{
		std::cout << "[ " << this->name << " ] " << "not enough energy" << std::endl;
		return ;
	}
	this->hit_point += amount;
	this->energy_points--;
	std::cout << "ClapTrap " << this->name << " be repaired " << amount << \
				", total hit point is" << this->hit_point << std::endl;
}

int ClapTrap::getAttackDamage()
{
	return this->attack_damage;
}

int ClapTrap::getHitPoint()
{
	return this->hit_point;
}

int ClapTrap::getEnergyPoint()
{
	return this->energy_points;
}