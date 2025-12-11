#include "PhoneBook.hpp"

PhoneBook::PhoneBook(int loc)
{
	size = 0;

	list[loc++].Add();
	while(true)
	{
		std::string cmd;
		std::getline(std::cin, cmd);
		if (loc == 8)
			size = 1;
		loc %= 8;
		switch (ft_is_cmd(cmd))
		{
		case 1:
			list[loc].Add();
			loc++;
			break;
		case 2:
			Search(loc);
			break;
		case 3:
			return ;
			break;
		default:
			std::cerr << "ERROR" << std::endl;
			break;
		}
	}
}

void PhoneBook::Search(int loc)
{
	int idx = 0;
	if (size == 1)
	{
		for (int i = 0; i < 8; i++)
			list[i].Search();
		print("INDEX");
		std::cin >> idx;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cerr << "ERROR" << std::endl;
		}
		if(idx >= 0 && idx <= 7)
			list[idx].Search();
		else
			std::cerr << "ERROR" << std::endl;
		std::cin.ignore(10000, '\n');
	}
	else
	{
		for (int i = 0; i < loc; i++)
			list[i].Search();
		print("INDEX");
		std::cin >> idx;
		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cerr << "ERROR" << std::endl;
		}
		if(idx >= 0 && idx <= 7)
			list[idx].Search();
		else
			std::cerr << "ERROR" << std::endl;
		std::cin.ignore(10000, '\n');
	}
}

PhoneBook::~PhoneBook(){};