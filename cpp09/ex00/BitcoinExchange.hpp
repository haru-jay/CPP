#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cctype>

class btc
{
public:
	btc();
	~btc();
	btc(const btc& rhs);
	btc& operator=(const btc& rhs);

	void loadDB(const std::string &path);
	void process(const std::string &path);

private:
	std::map<std::string, double> _db;
};

#endif