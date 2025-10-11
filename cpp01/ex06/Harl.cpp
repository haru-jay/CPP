#include "Harl.hpp"

void Harl::complain( std::string level )
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	int i;
	for(i = 0; i < 4; i++)
		if (level == levels[i])
			break;
	switch (i)
	{
	case 0:
		this->debug();
		// fall through
	case 1:
		this->info();
		// fall through
	case 2: 
		this->warning();
		// fall through
	case 3:
		this->error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

Harl::Harl(){};
Harl::~Harl(){};
void Harl::debug(){ std::cout << "[ DEBUG ]\n" << std::endl;}
void Harl::info(){ std::cout << "[ INFO ]\n" << std::endl;}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error()
{ 
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}