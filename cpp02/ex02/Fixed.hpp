#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
private:
	int  number_value;
	static const int fractional_bits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& rhs);
	~Fixed();
	Fixed& operator=(const Fixed &rhs);

	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	Fixed operator*(const Fixed &rhs);
	Fixed operator+(const Fixed &rhs);
	Fixed operator-(const Fixed &rhs);
	Fixed operator/(const Fixed &rhs);

	Fixed& operator++(); // 전위
	Fixed& operator--();
	Fixed operator++(int); // 후위
	Fixed operator--(int);

	static const Fixed& min(const Fixed &lhs, const Fixed &rhs);
	static const Fixed& max(const Fixed &lhs, const Fixed &rhs);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif