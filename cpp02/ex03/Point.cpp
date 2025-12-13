# include "Point.hpp"

Point::Point(Fixed x, Fixed y): x(x), y(y){}
Point::Point(const float x, const float y): x(x), y(y){}
Point::~Point(){}
Point::Point(const Point &rhs): x(rhs.x), y(rhs.y){}
Point Point::operator=(const Point &rhs)
{
	Point res(rhs);
	return res;
}

Fixed Point::getValueX(){ return this->x;}
Fixed Point::getValueY(){ return this->y;}
