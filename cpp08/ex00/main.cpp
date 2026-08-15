#include "easyfind.hpp"

int main()
{
	std::vector<int> numbers;

	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);
	try
	{
		std::vector<int>::iterator it = easyfind(numbers, 20);
		std::cout << *it << std::endl;
		std::vector<int>::iterator it2 = easyfind(numbers, 40);
		std::cout << *it2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}