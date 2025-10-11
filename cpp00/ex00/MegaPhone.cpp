#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char* argv[])
{
	if(argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string s(argv[1]);
		for (size_t i = 2; argv[i] != NULL; i++)
			s += argv[i];
		for (size_t i = 0; i <= s.length(); i++)
			s[i] = std::toupper(s[i]);
		std::cout << s << std::endl;
	}
	return 0;
}