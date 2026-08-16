#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>

class RPN
{
private:
	std::stack<int> _stack;
public:
	RPN();
	~RPN();
	RPN(const RPN& rhs);
	RPN& operator=(const RPN& rhs);

	int process(const std::string &expression);
};

#endif
