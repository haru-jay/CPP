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


Vector::Vector(Point lhs, Point rhs): \
		v_x(rhs.getValueX() - lhs.getValueX()), v_y(rhs.getValueY() - lhs.getValueY()){}
Vector::~Vector(){}
Vector::Vector(const Vector &rhs): v_x(rhs.v_x), v_y(rhs.v_y){}
Vector Vector::operator=(const Vector &rhs)
{
	Vector res(rhs);
	return res;
}

Fixed Vector::crossProduct(Vector &lhs, Vector &rhs)
{
	Fixed res(lhs.v_x * rhs.v_y - lhs.v_y * rhs.v_x);
	return res;
}