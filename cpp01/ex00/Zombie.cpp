#include "Zombie.hpp"

Zombie::Zombie(std::string s){ name = s;}
Zombie::~Zombie(){std::cout << "[DEBUG] " << name << ": destructor is activated" << std::endl;}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
