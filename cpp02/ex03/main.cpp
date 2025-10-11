# include "Point.hpp"

int main()
{
	Point a(0, 0);
    Point b(4, 0);
    Point c(2, 4);

    Point p1(2, 2); // 삼각형 내부
    Point p2(5, 1); // 삼각형 외부
    Point p3(2, 0); // 삼각형 변 위

    std::cout << "p1(2,2) in triangle? " << (bsp(a, b, c, p1) ? "YES" : "NO") << std::endl;
    std::cout << "p2(5,1) in triangle? " << (bsp(a, b, c, p2) ? "YES" : "NO") << std::endl;
    std::cout << "p3(2,0) in triangle? " << (bsp(a, b, c, p3) ? "YES" : "NO") << std::endl;

    return 0;
}