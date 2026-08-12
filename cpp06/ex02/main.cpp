#include "Base.hpp"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Base* base;
	base = generate();
	identify(base);
	identify(*base);

	delete base;
	return 0;

}