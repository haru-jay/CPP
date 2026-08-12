# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){};
AForm::AForm(std::string _name, int _gradeToSign, int _gradeToExecute):
_name(_name), _isSigned(false), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw AForm::GradeTooLowException();
};
AForm::~AForm(){};

AForm::AForm(const AForm& rhs): _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute){};

AForm& AForm::operator=(const AForm& rhs)
{
	if(this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
};

std::string AForm::getName() const
{
	return this->_name;
};

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() > this->_gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	else
		this->_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	this->executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
	os << rhs.getName()
	<< ", grade to sign: " << rhs.getGradeToSign()
	<< ", grade to execute: " << rhs.getGradeToExecute()
	<< ", signed: " << (rhs.getIsSigned() ? "yes" : "no");
	return os;
};

//getter
bool AForm::getIsSigned() const
{
	return this->_isSigned;
};
int	AForm::getGradeToSign() const
{
	return this->_gradeToSign;
};
int	AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
};

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is Too high\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is Too low\n";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed\n";
}
