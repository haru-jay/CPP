#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string _target): AForm("RobotomyRequestForm", 72, 45), _target(_target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs): AForm(rhs), _target(rhs._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}
void RobotomyRequestForm::executeAction() const
{
	std::cout << "* drilling noises *" << std::endl;
	if (std::rand() % 2 == 0)
			std::cout << _target << " has been robotomized successfully" << std::endl;
	else
			std::cout << "robotomy failed" << std::endl;
}