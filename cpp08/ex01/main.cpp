#include "Span.hpp"
#include <cstdlib>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	try
	{
		Span sp2 = Span(5);
		int arr[] = {1,10,5,9};
		sp2.addRange(arr, arr+4);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		const unsigned int N = 10000;
		std::vector<int> big;
		big.reserve(N);
		for (unsigned int i = 0; i < N; ++i)
			big.push_back(std::rand());

		Span sp3(N);
		sp3.addRange(big.begin(), big.end());
		std::cout << "10000 numbers -> shortest: " << sp3.shortestSpan() << std::endl;
		std::cout << "10000 numbers -> longest: " << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}