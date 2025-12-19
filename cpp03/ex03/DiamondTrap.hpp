#ifndef DIAMOND_HPP
# define DIAMOND_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& rhs);
	DiamondTrap operator=(const DiamondTrap& rhs);
	~DiamondTrap();

	void whoAmI();
	void attack(const std::string& target);
};

#endif