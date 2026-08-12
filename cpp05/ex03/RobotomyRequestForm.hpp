# ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib> //rand()
# include <ctime> 
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	std::string _target;

public:
	RobotomyRequestForm(std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
	~RobotomyRequestForm();

	void executeAction() const;
};

#endif