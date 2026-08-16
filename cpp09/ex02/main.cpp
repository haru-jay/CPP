#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	try
	{
		PmergeMe start;
		start.run(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}

// Ernst Jacobsthal
// J(0) = 0
// J(1) = 1
// J(n) = J(n-1) + 2 × J(n-2)
// J(n) = (2ⁿ - (-1)ⁿ) / 3