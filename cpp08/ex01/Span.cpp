#include "Span.hpp"

Span::Span(unsigned int N): _capacity(N)
{
	if(N >= INT_MAX)
		throw std::runtime_error("INT MAX");
	_number.reserve(N);
}
Span::~Span(){}
Span::Span(const Span &rhs): _capacity(rhs._capacity), _number(rhs._number){}
Span& Span::operator=(const Span &rhs)
{
	if(this != &rhs)
	{
		_capacity = rhs._capacity;
		_number = rhs._number;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if( _number.size() >= _capacity)
		throw std::runtime_error("Span is full");
	_number.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if(_number.size() < 2)
		throw std::runtime_error("Not enough numbers");
	std::vector<int> sorted = _number;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int> diffs(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());
	std::vector<int>::iterator minInt = std::min_element(diffs.begin() + 1, diffs.end());
	unsigned int shortest = static_cast<unsigned int>(*minInt);
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if(_number.size() < 2)
		throw std::runtime_error("Not enough numbers");
	
	std::vector<int> sorted = _number;
	std::sort(sorted.begin(), sorted.end());

	return static_cast<unsigned int>(sorted.back() - sorted.front());
}