#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string human_name;
	Weapon *wp;
public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weapon);
};

#endif