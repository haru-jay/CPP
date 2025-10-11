#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;

template <typename T>
void print(T arg) {
  std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print(T arg, Types... args) {
  std::cout << arg << ", ";
  print(args...);
}

int main()
{
	// print("hello", "\nworld\t", "r", 'd', 12, "\n", 13.3); --> c 11 부터 가능


	// int i;
	// std::string s;
	// // while(true)
	// {
	// 	// cin >> s;
	// 	// if(cin.fail())
	// 	// {
	// 	// 	cout << "Fail Need Number\n" << std::endl;
	// 	// 	cin.clear();
	// 	// 	cin.ignore(1000,'\n');
	// 	// 	continue;
	// 	// }
	// 	// if (s.empty())
	// 	// 	break;
	// 	// std::cout.setf(std::ios_base::hex, std::ios_base::basefield);
	// 	// cout << i << std::endl;
	// 	char peak = std::cin.rdbuf()->snextc();
	// 	std::cout << peak << std::endl;
	// 	std::cin >> s;
	// 	std::cout << "다시 읽으면 : " << s << std::endl;		
	// }
	// std::cin >> s;
	// char peek = std::cin.rdbuf()->snextc();
	// std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
	// std::cin >> s;
	// std::cout << "다시 읽으면 : " << s << std::endl;
	std::string s;
	std::ifstream in ("header1.hpp");
	int x;
	if (in.is_open())
	{
		// std::getline(in, s);
		// std::string all((std::istreambuf_iterator<char>(in)), (std::istreambuf_iterator<char>()));
		// in >> s;
		// std::cout << all << std::endl;
		in.read((char*)(&x), sizeof(int));
		std::cout << std::hex << x << std::endl;
	}
	in.close();
	// std::ifstream fi ("header2.hpp", std::ios::binary);
	// if (fi.is_open())
	// {
	// 	while(std::getline(fi,s))
	// 		std::cout << s << std::endl;
	// }
	// std::ofstream out ("test.txt", std::ios::app);
	// if (out.is_open())
	// {
	// 	out << "1:테스트\n";
	// 	out << "2:cc\n";
	// }

	return 0;
}