#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(const std::string& literal)
{
	double value;

	if(printSpecial(literal))
		return ;
	if(isChar(literal))
		value = static_cast<double>(literal[0]);
	else if(isInt(literal))
	{
		value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
	}
	else if(isFloat(literal))
	{
		value = static_cast<double>(std::strtod(literal.c_str(), NULL));
	}
	else if(isDouble(literal))
	{
		value = std::strtod(literal.c_str(), NULL);
	}
	else
	{
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		return ;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

bool isChar(const std::string& s)
{
	return s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
}
bool isInt(const std::string& s)
{
	if(s.empty())
		return false;

	size_t i = 0;
	if(s[0] == '+' || s[0] == '-')
		i++;
	if(i == s.length())
		return false;
	for (; i < s.length(); i++)
	{
		if(!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}
bool isFloat(const std::string& s)
{
	size_t i = 0;
	bool dotFlag = false;
	bool digitFlag = false;
	
	if(s.empty() || s[s.length() - 1] != 'f')
		return false;
	if(s[0] == '+' || s[0] == '-')
		i++;
	for (; i < s.length() - 1; i++)
	{
		if(s[i] == '.')
		{
			if(dotFlag)
				return false;
			dotFlag = true;
		}
		else if(std::isdigit(static_cast<unsigned char>(s[i])))
			digitFlag = true;
		else
			return false;
	}
	return digitFlag;
}

bool isDouble(const std::string& s)
{
	size_t i = 0;
	bool dotFlag = false;
	bool digitFlag = false;
	
	if(s.empty())
		return false;
	if(s[0] == '+' || s[0] == '-')
		i++;
	for (; i < s.length(); i++)
	{
		if(s[i] == '.')
		{
			if(dotFlag)
				return false;
			dotFlag = true;
		}
		else if(std::isdigit(static_cast<unsigned char>(s[i])))
			digitFlag = true;
		else
			return false;
	}
	return digitFlag;
}


void printChar(double value)
{
	std::cout << "char: ";
	if(value < 0 || value > 127 || value != std::floor(value))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	unsigned char c = static_cast<unsigned char>(value);
	if(std::isprint(c))
		std::cout << '\'' << c << '\''<< std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void printInt(double value)
{
	std::cout << "int: ";
	if(value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	int i = static_cast<int>(value);
	std::cout << i << std::endl;
}

void printFloat(double value)
{
	std::cout << "float: ";
	if(value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	float i = static_cast<float>(value);
	if(value == std::floor(value))
		std::cout << std::fixed << std::setprecision(1) << i << 'f' << std::endl;
	else
		std::cout << i << 'f' << std::endl;
}

void printDouble(double value)
{
	std::cout << "double: ";
	if(value == std::floor(value))
		 std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	else
		std::cout << value << std::endl;
}

bool printSpecial(const std::string& s)
{
	if (s == "nan" || s == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return true;
	}
	else if (s == "+inf" || s == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return true;
	}
	else if (s == "-inf" || s == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return true;
	}
	return false;
}
