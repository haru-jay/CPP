#include "Zombie.hpp"

Zombie::Zombie(){}
Zombie::Zombie(std::string s){ name = s;}
Zombie::~Zombie(){std::cout << "[DEBUG] " << name << ": destructor is activated" << std::endl;}

void Zombie::ZombieName(std::string s){	name = s;}
void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
