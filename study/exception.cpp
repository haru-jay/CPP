#include <iostream>
#include <stdexcept>
#include <vector>

int main()
{
	std::vector<int> vec;
	int idx;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	
	std::cin >> idx;
	
	try {
		std::cout << vec.at(idx) << std::endl;
	} catch (const std::out_of_range& e) {
		std::cout << "예외발생: " << e.what() << std::endl;
	}
}