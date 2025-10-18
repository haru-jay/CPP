#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

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

public:
	Contact();
	~Contact();
	void Add();
	void Search();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetNickName();
	std::string GetPhoneNumber();
};

#endif