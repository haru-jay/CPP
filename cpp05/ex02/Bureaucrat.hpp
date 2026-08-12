#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class AForm;

class Bureaucrat
{
private:
	int					_grade; // 1 ~ 150
	const std::string	_name;

public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(const Bureaucrat& rhs);
	Bureaucrat& operator=(const Bureaucrat& rhs);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void setGrade(int _grade);

	void levelUp();
	void levelDown();

	void signForm(AForm& form);
	void executeForm(AForm const & form) const;

	class GradeTooHighException: public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);



#endif
