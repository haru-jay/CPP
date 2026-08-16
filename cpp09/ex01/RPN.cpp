#include "RPN.hpp"

RPN::RPN(){};
RPN::~RPN(){};
RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
		_stack = rhs._stack;
	return *this;
};
RPN::RPN(const RPN& rhs)
{
	_stack = rhs._stack;
};

int RPN::process(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;
	while (iss >> token)
	{
		if(token == "+" || token == "-" || token == "*" || token == "/")
		{
			if(_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			int result = 0;
			if(token == "+")
				result = a + b;
			else if(token == "-")
				result = a - b;
			else if(token == "*")
				result = a * b;
			else
			{
				if(b == 0)
					throw std::runtime_error("Error");
				result = a / b;
			}
			_stack.push(result);
		}
		else
		{
			if(token.size() != 1 || !std::isdigit(static_cast<unsigned char>(token[0])))
				throw std::runtime_error("Error");
			_stack.push(std::atoi(token.c_str()));
		}
	}
	if(_stack.size() != 1)
		throw std::runtime_error("Error");
	return _stack.top();
}