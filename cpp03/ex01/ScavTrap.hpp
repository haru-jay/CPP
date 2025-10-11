#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	ScavTrap(std::string name);
	~ScavTrap();
};

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << "[ScavTrap] constructor Activate" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] destructor Activate" << std::endl;
}


#endif