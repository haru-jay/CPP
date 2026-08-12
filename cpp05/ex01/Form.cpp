# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150){};
Form::Form(std::string _name, int _gradeToSign, int _gradeToExecute):
_name(_name), _isSigned(false), _gradeToSign(_gradeToSign), _gradeToExecute(_gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
};
Form::~Form(){};

Form::Form(const Form& rhs): _name(rhs._name), _isSigned(rhs._isSigned), _gradeToSign(rhs._gradeToSign), _gradeToExecute(rhs._gradeToExecute){};

Form& Form::operator=(const Form& rhs)
{
	if(this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
};

std::string Form::getName() const
{
	return this->_name;
};

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() > this->_gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	else
		this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	os << rhs.getName()
	<< ", grade to sign: " << rhs.getGradeToSign()
	<< ", grade to execute: " << rhs.getGradeToExecute()
	<< ", signed: " << (rhs.getIsSigned() ? "yes" : "no");
	return os;
};

//getter
bool Form::getIsSigned() const
{
	return this->_isSigned;
};
int	Form::getGradeToSign() const
{
	return this->_gradeToSign;
};
int	Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
};

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is Too high\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is Too low\n";
}