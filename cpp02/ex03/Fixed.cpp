#include "Fixed.hpp"

Fixed::Fixed(): number_value(0){}
Fixed::~Fixed(){}
Fixed::Fixed(const Fixed& rhs){*this = rhs;}
Fixed& Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
	{
		this->number_value = rhs.number_value;
	}
	return *this;
}

int Fixed::getRawBits(void) const {	return number_value;}
void Fixed::setRawBits(int const raw) {	this->number_value = raw;}

Fixed::Fixed(const int value){ number_value = value << fractional_bits;}
int Fixed::toInt() const { return number_value >> fractional_bits;}
Fixed::Fixed(const float value){ number_value = roundf(value * (1 << fractional_bits));}

float Fixed::toFloat() const { return (float)number_value / (1 << fractional_bits);}

std::ostream& operator<<(std::ostream& os, const Fixed &copy)
{	
	os << copy.toFloat();
	return os;
}


bool Fixed::operator>(const Fixed &rhs) const { return this->getRawBits() < rhs.getRawBits();}
bool Fixed::operator>=(const Fixed &rhs) const { return this->getRawBits() >= rhs.getRawBits();}
bool Fixed::operator==(const Fixed &rhs) const { return this->getRawBits() == rhs.getRawBits();}
bool Fixed::operator!=(const Fixed &rhs) const { return this->getRawBits() != rhs.getRawBits();}
bool Fixed::operator<(const Fixed &rhs) const { return this->getRawBits() < rhs.getRawBits();}
bool Fixed::operator<=(const Fixed &rhs) const { return this->getRawBits() <= rhs.getRawBits();}

Fixed Fixed::operator*(const Fixed &rhs)
{
	Fixed res;
	res.setRawBits((this->getRawBits() * rhs.getRawBits()) >> fractional_bits);
	return res;
}

Fixed Fixed::operator+(const Fixed &rhs)
{
	Fixed res;
	res.setRawBits(this->getRawBits() + rhs.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	Fixed res;
	res.setRawBits(this->getRawBits() - rhs.getRawBits());
	return res;
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	Fixed res;
	if (rhs.getRawBits() == 0)
	{
		throw std::runtime_error("Division by zero");
		return *this;
	}
	res.setRawBits((this->getRawBits() << fractional_bits) / rhs.getRawBits());
	return res;
}
//전위 연산자
Fixed& Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}
Fixed& Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

//후위 연산자
Fixed Fixed::operator++(int) 
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return tmp;
}
Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return tmp;
}

const Fixed& Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs.getRawBits() < rhs.getRawBits()) ? lhs : rhs;
}
const Fixed& Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	return (lhs.getRawBits() > rhs.getRawBits()) ? lhs : rhs;
}