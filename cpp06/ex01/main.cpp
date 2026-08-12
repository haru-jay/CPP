#include "Serializer.hpp"

int main()
{
	Data d;
	d.id = 42;
	Data* original = &d;

	uintptr_t ptr = Serializer::serialize(original);
	Data* convert = Serializer::deserialize(ptr);
	
	std::cout << original << std::endl;
	std::cout << ptr << std::endl;
	std::cout << convert << std::endl;
	if (original == convert)
		std::cout << "SUCCESS" << std::endl;
	else
		std::cout << "FAILURE" << std::endl;
	
	return 0;
}