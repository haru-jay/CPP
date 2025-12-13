# include "Vector.hpp"

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