# ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter(void);
public:
	static void convert(const std::string& literal);
	~ScalarConverter();
};

bool isChar(const std::string& s);
bool isInt(const std::string& s);
bool isFloat(const std::string& s);
bool isDouble(const std::string& s);
bool printSpecial(const std::string& s);

void printChar(double value);
void printInt(double value);
void printFloat(double value);
void printDouble(double value);


#endif