#include "Harl.hpp"

void Harl::complain( std::string level )
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	void (Harl::*func[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*func[i])();
			break;
		}
	}
}

Harl::Harl(){};
Harl::~Harl(){};
void Harl::debug(){ std::cout << "[debug]" << std::endl;}
void Harl::info(){ std::cout << "[info]" << std::endl;}
void Harl::warning(){ std::cout << "[warning]" << std::endl;}
void Harl::error(){ std::cout << "[error]" << std::endl;}