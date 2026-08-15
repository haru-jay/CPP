#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
# include <iterator>
# include <stdexcept>
# include <numeric>

class Span
{
private:
	unsigned int _capacity;
	std::vector<int> _number;
public:
	Span(unsigned int N);
	~Span();
	Span(const Span &rhs);
	Span& operator=(const Span &rhs);

	void addNumber(int number);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	template <typename InputIterator>
	void addRange(InputIterator first, InputIterator last)
	{
		if (_number.size() + std::distance(first, last) > _capacity)
			throw std::runtime_error("Span is full");
		_number.insert(_number.end(), first, last);
	}
};


#endif