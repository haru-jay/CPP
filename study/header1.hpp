#include <iostream>
#include "header2.hpp"

namespace header1
{
	int foo()
	{
		std::cout << "1:foofoo\n" << std::endl;
		header2::foo2();
		return 0;
	}
}