#include "Harl.hpp"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "error" << std::endl;
		return 1;
	}
	std::string level = argv[1];
	Harl a;
	a.complain(level);
	return 0;
}