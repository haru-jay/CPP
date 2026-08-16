#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if(argc != 2 || argv[1] == NULL)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	try
	{
		std::string path(argv[1]);
		btc bitcoinDB;
		bitcoinDB.process(path);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}


	return 0;
}