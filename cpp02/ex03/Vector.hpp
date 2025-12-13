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
	Vector(const Vector &rhs);
	Vector operator=(const Vector &rhs);
	~Vector();

	static Fixed crossProduct(Vector &lhs, Vector &rhs);
};

#endif