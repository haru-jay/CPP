#include <iostream>

class Complex
{
	private:
		double real, img;

	public:
	Complex(double real, double img): real(real), img(img){};
	Complex(const Complex& c) { real = c.real, img = c.img; }
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;
	operator int(){ return real + 1;}
	void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) const
{
	Complex temp(real + c.real, img + c.img);
	return temp;
}

Complex Complex::operator-(const Complex& c) const{
	Complex temp(real - c.real, img - c.img);
	return temp;
}

Complex Complex::operator*(const Complex& c) const {
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}

Complex Complex::operator/(const Complex& c) const {
	Complex temp(
		(real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
		(img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
	return temp;
}

int main()
{
	Complex a(1.0, 2.0);
	Complex b(2.0, 3.0);
	Complex c = a + b;
	Complex d(56.1, 10.0);
	c = a - b;
	c.println();
	int temp = d;
	double dd = 123456.02;

	int t = static_cast<int>(dd);
	
	std::cout << 1+3 << temp << std::endl;
	
	// // Complex 객체를 int로 변환
	// int x = a;
	// std::cout << "a를 int로 변환한 값: " << x << std::endl;
	std::cout << t << std::endl;
}