#include <iostream>
#include <string.h>

// #include "header1.hpp"
// #include "header2.hpp"

using std::cout;
using std::endl;
using std::cin;

class Food
{
private:


public:
int date_year_;
int date_month_;
int date_day_;
int price_;
char *name_;

// bool Food::SetDate(int date_year, int date_month, int date_day)
// {
// 	if (isdigit(date_year) || isdigit(date_month) || isdigit(date_day))
// 		return(false);
// 	date_year_ = date_year;
// 	date_month_ = date_month;
// 	date_day_ = date_day;
// 	return(true);
// }
	Food();
	~Food();
	Food(int date_day, int date_month, int date_year, int price, const char *name);
	int ShowPrice();
	int& ShowYear();
	int ShowDay() const;
};

Food::Food() : date_year_(0), date_month_(0), date_day_(0), price_(0), name_(NULL){}

Food::Food(int date_day, int date_month, int date_year,int price, const char *name)
{
	date_year_ = date_year;
	date_month_ = date_month;
	date_day_ = date_day;
	price_ = price;
	name_ = new char[strlen(name) + 1];
	strcpy(name_,name);
}

Food::~Food()
{
	delete[] name_;
}
int Food::ShowPrice()
{
	return this->price_;
}

int& Food::ShowYear()
{
	return this->date_year_;
}
int Food::ShowDay() const
{
	return 10;
}

class A {
  int x;

 public:
  A(int c) : x(c) {}

  int& access_x() { return x; }
  int get_x() { return x; }
  void show_x() { std::cout << x << std::endl; }
};

int main()
{
	// std::cout << "hello" << "1\n2" << std::endl << "3" << std::endl;
	// std::cout << std::endl;
	// std::cout << "world" << std::endl;
	// header1::foo();
	// int user_input,sum = 0;
	// const char *s = "sum: ";
	// char s2[100];

	// std::cin >> user_input;
	// std::cin >> s2;
	// for(int i=0; i<=user_input ; i++)
	// 	sum += i;
	// std::cout << s << sum << s2 << std::endl;
	
// 	cin >> user_input;
// 	switch (user_input)
// 	{
// 		case 1:
// 			cout << "1: 하나" << endl;
// 			break;
// 		case 2: 
// 			cout << "2: 둘" << endl;
// 			break;
// 		case 3:
// 			cout << "3: 셋" << endl;
// 		[[fallthrough]]; //std=c++11 이상부터
// 		default:
// 			cout << "enter: 1~3" << endl;
// 			break;
// 	}


	// int x;
	// int& y = x;
	// int& z = y;

	// x = 1;
	// std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	// y = 2;
	// std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	// z = 3;
	// std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	// char s[100] = "hello";
	// char &p = *s;
	// int a[2][2] = {1,2,3,4};
	// int (&b)[2][2] = a;

	// p = 'a';
	// *(&p+1) = 'b';
	// (&p)[2] = 'c';
	// *s = 'h';
	// cout << &p << endl;
	// cout << &a << endl;
	// cout << &b << endl;


	// char *p2 = s;

	// cout << p2 << endl;

	// const char *tmp = "temp";

	// int *integral = new int;
	// *integral = 1000;
	// delete integral;

	// int user_input;
	
	// std::cin >> user_input;
	// std::cout << "input number\n" << endl;
	// int *local = new int[user_input];

	// for(int i = 0; i<user_input; i++)
	// {
	// 	local[i] = i;
	// 	cout << local[i] << endl;
	// }
	// delete[] local;

	// int date_year;
	// int date_month;
	// int date_day;

	// cin >> date_year;
	// cin >> date_month;
	// cin >> date_day;
	Food *burger[100];
	burger[0] = new Food(25,12,2025, 3000, "땃쥐");
	burger[1] = new Food(25,12,2025, 5000, "불고기");

	cout << burger[0]->name_ <<endl;
	cout << burger[1]->ShowPrice() << endl;
	cout << burger[1]->ShowYear() << endl;
	burger[1]->ShowYear() = 2030;
	cout << burger[1]->ShowYear() << endl;
	cout << burger[0]->ShowDay() << endl;
	delete burger[0];
	delete burger[1];

	return 0;
}