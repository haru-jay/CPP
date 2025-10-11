#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

void print(const char *msg);
int ft_is_cmd(std::string s);
void ft_over_ten(std::string st);

class Contact
{
private:
	int			index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
public:
	Contact();
	~Contact();
	void Add();
	void Search();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickName();
	std::string GetPhoneNumber();
	std::string GetMemo();

	void SetFirstName(std::string fname);
};

Contact::Contact(){};
Contact::~Contact(){};

std::string Contact::GetFirstName(){return this->first_name;}
std::string Contact::GetLastName(){return this->last_name;}
std::string Contact::GetNickName(){return this->nickname;}
std::string Contact::GetPhoneNumber(){return this->phone_number;}
std::string Contact::GetMemo(){return this->darkest_secret;}

void Contact::Add()
{		
	print("Enter first name");
	std::getline(std::cin, first_name);
	print("Enter last name");
	std::getline(std::cin, last_name);
	print("Enter nick name");
	std::getline(std::cin, nickname);
	print("Enter phone_number");
	std::getline(std::cin, phone_number);
}

void Contact::Search()
{
	ft_over_ten(this->GetFirstName());
	std::cout << "|";
	ft_over_ten(this->GetLastName());
	std::cout << "|";
	ft_over_ten(this->GetNickName());
	std::cout << "|";
	ft_over_ten(this->GetPhoneNumber());
	std::cout << std::endl;
}

class PhoneBook
{
private:
	int size;
	Contact list[8];
public:
	PhoneBook(int i);
	~PhoneBook();
	void Search(int loc);
};

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
		case 1: // ADD
			list[loc].Add();
			loc++;
			break;
		case 2: // SEARCH
			Search(loc);
			break;
		case 3: // EXIT
			return ;
			break;
		default:
			print("\n=== ONLY ===\n[1]ADD\n[2]SEARCH\n[3]EXIT");
			break;
		}
	}
}

void PhoneBook::Search(int loc)
{
	if (size == 1)
	{
		for (int i = 0; i < 8; i++)
			list[i].Search();
	}
	else
	{
		for (int i = 0; i < loc; i++)
			list[i].Search();
	}
}

PhoneBook::~PhoneBook(){};

#endif