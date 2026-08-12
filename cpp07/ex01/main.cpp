#include "iter.hpp"

int main()
{
	std::cout << "int" << std::endl;
	int arr[4] = {0,1,2,3};
	::iter(arr, 4, printValue<int>);

	std::cout << "const int" << std::endl;
	const int arr2[4] = {0,1,2,3};
	::iter(arr2, 4, printValue<int>);

	std::cout << "float" << std::endl;
	float arr3[4] = {0,1,2,3};
	::iter(arr3, 4, printValue<float>);

	std::cout << "string" << std::endl;
	std::string arr4[4] = {"0","1","2","3"};
	::iter(arr4, 4, printValue<std::string>);

	return 0;
}