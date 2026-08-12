# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "----- executeForm: not signed -----" << std::endl;
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm form("home");
		bob.executeForm(form);
	}

	std::cout << "\n----- executeForm: grade too low -----" << std::endl;
	{
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm form("garden");
		intern.signForm(form);
		intern.executeForm(form);
	}

	std::cout << "\n----- executeForm: success (ShrubberyCreationForm) -----" << std::endl;
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm form("park");
		bob.signForm(form);
		bob.executeForm(form);
	}

	std::cout << "\n----- executeForm: success (RobotomyRequestForm) -----" << std::endl;
	{
		Bureaucrat bob("Bob", 1);
		RobotomyRequestForm form("Bender");
		bob.signForm(form);
		bob.executeForm(form);
	}

	std::cout << "\n----- executeForm: success (PresidentialPardonForm) -----" << std::endl;
	{
		Bureaucrat bob("Bob", 1);
		PresidentialPardonForm form("Ford");
		bob.signForm(form);
		bob.executeForm(form);
	}

	return 0;
}
