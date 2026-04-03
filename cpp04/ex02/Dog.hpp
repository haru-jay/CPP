#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain*	brain;
public:
	Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);
	virtual ~Dog();

	virtual void makeSound() const;
	Brain* getBrain() const;
};

#endif
