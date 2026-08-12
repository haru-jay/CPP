# ifndef AFORM_HPP
#define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	AForm();
	AForm(std::string _name, int _gradeToSign, int _gradeToExecute);
	AForm(const AForm& rhs);
	AForm& operator=(const AForm& rhs);
	virtual ~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);

	void execute(Bureaucrat const & executor) const;

	virtual void executeAction() const = 0;

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

	class FormNotSignedException: public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& rhs);
#endif