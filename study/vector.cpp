#include <iostream>
#include <vector>
#include <string>

template <typename T>
void ft_print_vector(std::vector<T>& vec)
{
	for(typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		std::cout << *itr << std::endl;
}

int main ()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	std::vector<std::string> s;

	// std::cout << "====변경 전====\n" << std::endl;
	// ft_print_vector(vec);
	// vec.insert(vec.begin()+3, 50);
	// std::cout << "====변경 후====\n" << std::endl;
	// ft_print_vector(vec);
	// std::cout << "====제거 후====\n" << std::endl;
	// vec.erase(vec.begin()+1);
	// ft_print_vector(vec);

	s.push_back("hello\n");
	s.push_back("world\n");
	s.push_back("this is\n");
	s.push_back("C++\n");
//	s.emplace_back("C++\n"); c++11부터

	ft_print_vector(s);
	std::cout << s.at(3) << std::endl;
	std::vector<std::string> s_copy;
	s_copy.assign(s.begin()+1,s.end()-1);
	// ft_print_vector(s_copy);

	s_copy.pop_back();
	ft_print_vector(s_copy);
	// std::vector<int>::iterator itr = vec.begin() + 6;
	// std::cout << "3 번째 원소 :: " << *itr << std::endl;

	std::vector<int> num;
	num.pop_back(10);
	
}