# include "Vector.hpp"

bool same_sign(Fixed s1, Fixed s2, Fixed s3) 
{
	return  (s1.toFloat() > 0 && s2.toFloat() > 0 && s3.toFloat() > 0) ||\
			(s1.toFloat() < 0 && s2.toFloat() < 0 && s3.toFloat() < 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Vector a_b(a, b);
	Vector a_p(a, point);
	Vector b_c(b, c);
	Vector b_p(b, point);
	Vector c_a(c, a);
	Vector c_p(c, point);

	Fixed sign_1 = Vector::crossProduct(a_b, a_p);
	Fixed sign_2 = Vector::crossProduct(b_c, b_p);
	Fixed sign_3 = Vector::crossProduct(c_a, c_p);

	if (same_sign(sign_1, sign_2, sign_3))
		return true;
	return false;
}