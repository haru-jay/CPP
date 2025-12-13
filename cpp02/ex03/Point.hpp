#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point(Fixed x, Fixed y);
	Point(const float x, const float y);
	Point(const Point &rhs);
	Point operator=(const Point &rhs);
	~Point();

	Fixed getValueX();
	Fixed getValueY();
};

bool same_sign(Fixed s1, Fixed s2, Fixed s3);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif