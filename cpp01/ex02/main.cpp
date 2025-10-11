#include <string>
#include <iostream>

int main()
{
	std::string stringValue("HI THIS IS BRAIN");

	std::string* stringPTR = &stringValue;
	std::string& stringREF = stringValue;

	std::cout << "=========The memory address=========" << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;
	std::cout << "stringREF: " << &stringREF <<std::endl;

	std::cout << "=========The value pointed=========" << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;

	return 0;
}