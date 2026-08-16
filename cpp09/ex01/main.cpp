#include "RPN.hpp"

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::string stringInput(argv[1]);
	if (stringInput.find_first_not_of("0123456789-+*/ ") != std::string::npos)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try
	{
		RPN rpn;
		int result = rpn.process(stringInput);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;

}