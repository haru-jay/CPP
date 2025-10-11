#include "Contact.hpp"

void ft_over_ten(std::string st)
{
	if (st.length() > 10)
	{
		for (size_t i = 0; i < 9; i++)
			std::cout << st[i];
		std::cout << ".";
	}
	else
		std::cout << st;
}

int ft_is_cmd(std::string s)
{
	if (s == "ADD")
		return 1;
	else if (s == "SEARCH")
		return 2;
	else if (s == "EXIT")
		return 3;
	else
		return 0;
}

void print(const char *msg)
{
	std::cout << msg << std::endl;
}

int main()
{
	PhoneBook phone(0);
	return 0;
}