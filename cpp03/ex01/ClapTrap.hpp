#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
private:
	std::string name;
	int 		hit_point;
	int 		energy_points;
	int			attack_damage;
public:
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hit, int energy, int attack);
	ClapTrap(const ClapTrap& rhs);
	ClapTrap operator=(const ClapTrap& rhs);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	
	int getAttackDamage();
	int getHitPoint();
	int getEnergyPoint();
};

#endif