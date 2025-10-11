#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "Point.hpp"

class Vector
{
private:
	Fixed v_x;
	Fixed v_y;
public:
	Vector(Point lhs, Point rhs);
	~Vector();

	static Fixed crossProduct(Vector &lhs, Vector &rhs);
};

Vector::Vector(Point lhs, Point rhs): \
		v_x(rhs.getValueX() - lhs.getValueX()), v_y(rhs.getValueY() - lhs.getValueY()){}
Vector::~Vector(){}

Fixed Vector::crossProduct(Vector &lhs, Vector &rhs)
{
	Fixed res(lhs.v_x * rhs.v_y - lhs.v_y * rhs.v_x);
	return res;
}


#endif