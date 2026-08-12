#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cout << "[Error]: argument error" << std::endl;
		return 1; 
	}
	std::string str(argv[1]);

	ScalarConverter::convert(str);
}