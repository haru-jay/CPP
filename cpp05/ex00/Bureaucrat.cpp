# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _grade(150), _name("default") {};
Bureaucrat::Bureaucrat(std::string _name, int _grade): _name(_name)
{
	this->setGrade(_grade);
};

Bureaucrat::Bureaucrat(const Bureaucrat& rhs): _name(rhs._name)
{
	*this = rhs;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}
Bureaucrat::~Bureaucrat(){};

int Bureaucrat::getGrade() const
{
	return this->_grade;
};

std::string Bureaucrat::getName() const
{
	return this->_name;
};

void Bureaucrat::setGrade(int _grade)
{
	if(_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = _grade;
}

void Bureaucrat::levelUp()
{
	this->setGrade(this->getGrade() - 1);
}

void Bureaucrat::levelDown()
{
	this->setGrade(this->getGrade() + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is Too high\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is Too low\n";
}