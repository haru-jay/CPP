#include "Contact.hpp"

Contact::Contact(){};
Contact::~Contact(){};

std::string Contact::GetFirstName(){return this->first_name;}
std::string Contact::GetLastName(){return this->last_name;}
std::string Contact::GetNickName(){return this->nickname;}
std::string Contact::GetPhoneNumber(){return this->phone_number;}

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