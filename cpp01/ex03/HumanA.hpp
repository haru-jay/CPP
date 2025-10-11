#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string human_name;
	Weapon &wp;
public:
	HumanA(std::string name, Weapon &wp);
	~HumanA();
	void attack();
};

#endif