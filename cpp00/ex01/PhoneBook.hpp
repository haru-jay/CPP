#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

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

#endif