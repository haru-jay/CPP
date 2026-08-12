# ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	Form();
	Form(std::string _name, int _gradeToSign, int _gradeToExecute);
	Form(const Form& rhs);
	Form& operator=(const Form& rhs);
	~Form();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);
	
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

std::ostream& operator<<(std::ostream& os, const Form& rhs);
#endif