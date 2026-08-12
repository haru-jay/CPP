# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
	std::cout << "----- Form construction -----" << std::endl;
	try { std::cout << Form("Vacation Request", 5, 10) << std::endl; }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try { std::cout << Form("Broken Form", 0, 10) << std::endl; }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	try { std::cout << Form("Broken Form", 5, 200) << std::endl; }
	catch (std::exception& e) { std::cout << e.what() << std::endl; }

	std::cout << "\n----- signForm: success case -----" << std::endl;
	{
		Bureaucrat bob("Bob", 3);
		Form form("Vacation Request", 5, 10);
		bob.signForm(form);
		std::cout << form << std::endl;
	}

	std::cout << "\n----- signForm: failure case (grade too low) -----" << std::endl;
	{
		Bureaucrat intern("Intern", 145);
		Form form("Budget Approval", 5, 10);
		intern.signForm(form);
		std::cout << form << std::endl;
	}

	std::cout << "\n----- signForm: boundary case (grade == gradeToSign) -----" << std::endl;
	{
		Bureaucrat exact("Exact", 5);
		Form form("Boundary Form", 5, 10);
		exact.signForm(form);
		std::cout << form << std::endl;
	}

	return 0;
}
