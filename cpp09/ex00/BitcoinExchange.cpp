#include "BitcoinExchange.hpp"

btc::btc()
{
	btc::loadDB("data.csv");
}
btc::~btc(){}
btc::btc(const btc& rhs)
{
	_db = rhs._db;
}
btc& btc::operator=(const btc& rhs)
{
	if (this != &rhs)
	{
		this->_db = rhs._db;
	}
	return *this;
}

void btc::loadDB(const std::string &path)
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open file.");
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line))
	{
		if(line.empty())
			continue ;
		size_t pos = line.find(',');
		if(pos == std::string::npos || pos+1 == line.size())
			continue ;
		_db[line.substr(0,pos)] = std::strtod(line.substr(pos + 1).c_str(), NULL);
	}
}

static bool isSpaceChar(char c)
{
	return std::isspace(static_cast<unsigned char>(c));
}

bool isDate(const std::string &date)
{
	if(date.size() != 10 ||  date[4] != '-' || date[7] != '-')
		return false;
	for(int i = 0; i < 10 ; i++)
	{
		if(i == 4 || i == 7)
			continue;
		if(!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	static const int daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		maxDay = 29;

	if (day < 1 || day > maxDay)
		return false;
	return true;
}

void btc::process(const std::string &path)
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open file.");
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), isSpaceChar), line.end());
		if(line.empty())
			continue ;
		size_t pos = line.find('|');
		if(pos == std::string::npos || pos+1 == line.size())
		{
			std::cerr << "Error: bad input => " << line.substr(0, pos) << std::endl;
			continue ;
		}
		std::string date(line.substr(0,pos));
		if(!isDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		std::string value(line.substr(pos+1));
		char* endPtr;
		double valueDouble = std::strtod(value.c_str(), &endPtr);
		if(endPtr == value.c_str() || *endPtr != '\0')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if(valueDouble < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if(valueDouble > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, double>::iterator it = _db.lower_bound(date);
		if(it != _db.end() && it->first == date)
		{
			std::cout << date << " => " << valueDouble << " = " << valueDouble * it->second << std::endl;
			continue;
		}
		else if (it == _db.begin())
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		else
		{
			--it;
			std::cout << date << " => " << valueDouble << " = " << valueDouble * it->second << std::endl;
			continue;
		}
	}
}

// 1) " | " 기준으로 날짜/값 분리
// 2) 날짜 형식·범위 검증
// 3) 값 숫자 여부·범위(0~1000) 검증
// 4) 검증 실패 시 std::cerr로 에러 출력 후 continue
// 5) 통과했으면 _db에서 조회 (lower_bound로 가장 가까운 날짜 찾기)
// 6) "날짜 => 값 = 결과" 형식으로 std::cout 출력