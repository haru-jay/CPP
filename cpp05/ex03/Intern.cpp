# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

static AForm* createShrubbery(const std::string& _name) {return new ShrubberyCreationForm(_name);}
static AForm* createRobotomy(const std::string& _name) {return new RobotomyRequestForm(_name);}
static AForm* createPardon(const std::string& _name) {return new PresidentialPardonForm(_name);}

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern& rhs)
{
	(void)rhs;
}
Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return (*this);
}

AForm* Intern::makeForm(const std::string& whichForm, const std::string& _name)
{
	int i = 0;
	AForm* form = NULL;
	std::string formName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*formfuc[3])(const std::string&) = {createShrubbery, createRobotomy, createPardon};

	for(; i < 3 ; i++)
	{
		if(whichForm == formName[i])
			break;
	}
	if(i == 3)
	{
		std::cout << "[Error]: does not exist." << std::endl;
		return NULL;
	}
	form = formfuc[i](_name);
	std::cout << "Intern creates " << whichForm << std::endl;
	return form;
}
