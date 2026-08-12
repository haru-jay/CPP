# include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Intern someRandomIntern;
	Bureaucrat bob("Bob", 1);

	std::cout << "----- Intern::makeForm: success (ShrubberyCreationForm) -----" << std::endl;
	{
		AForm* form = someRandomIntern.makeForm("shrubbery creation", "home");
		if (form)
		{
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n----- Intern::makeForm: success (RobotomyRequestForm) -----" << std::endl;
	{
		AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form)
		{
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n----- Intern::makeForm: success (PresidentialPardonForm) -----" << std::endl;
	{
		AForm* form = someRandomIntern.makeForm("presidential pardon", "Ford");
		if (form)
		{
			bob.signForm(*form);
			bob.executeForm(*form);
			delete form;
		}
	}

	std::cout << "\n----- Intern::makeForm: unknown form name -----" << std::endl;
	{
		AForm* form = someRandomIntern.makeForm("some nonexistent form", "nobody");
		if (form)
			delete form;
		else
			std::cout << "makeForm() returned NULL as expected" << std::endl;
	}

	std::cout << "\n----- Intern::makeForm: grade too low to sign -----" << std::endl;
	{
		Bureaucrat lowGradeBureaucrat("Intern", 150);
		AForm* form = someRandomIntern.makeForm("shrubbery creation", "garden");
		if (form)
		{
			lowGradeBureaucrat.signForm(*form);
			lowGradeBureaucrat.executeForm(*form);
			delete form;
		}
	}

	return 0;
}
