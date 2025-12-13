#include "Fixed.hpp"

Fixed::Fixed(): number_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}
Fixed& Fixed::operator=(const Fixed& copy)
{
	if (this != &copy)
	{
		this->number_value = copy.number_value;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return number_value;
}
void Fixed::setRawBits(int const raw)
{
	this->number_value = raw;
}


Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	number_value = value << fractional_bits;
}

int Fixed::toInt() const
{
	return number_value >> fractional_bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	number_value = roundf(value * (1 << fractional_bits));
}

float Fixed::toFloat() const
{
	return (float)number_value / (1 << fractional_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed &copy)
{	
	os << copy.toFloat();
	return os;
}