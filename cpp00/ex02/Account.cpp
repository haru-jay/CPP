#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount = _totalAmount + initial_deposit;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";created" << std::endl;
}
Account::~Account()
{
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";closed" << std::endl;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< " accounts:" << getNbAccounts() \
				<< ";total:" << getTotalAmount() \
				<< ";deposits:" << getNbDeposits()\
				<< ";withdrawals:" << getNbWithdrawals()\
				<< std::endl;
}

int	Account::getNbAccounts(){ return _nbAccounts;}
int Account::getTotalAmount(){ return _totalAmount;}
int Account::getNbWithdrawals(){ return _totalNbWithdrawals;}
int Account::getNbDeposits(){ return _totalNbDeposits;}
int Account::checkAmount( void ) const { return _amount;}

void Account::makeDeposit( int deposit )
{
	int p_amount = _amount;
	_amount = p_amount + deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";p_amount:" << p_amount \
				<< ";deposit:" << deposit \
				<< ";amount:" << _amount \
				<< ";nb_deposits:" << _nbDeposits \
				<< std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;
	_displayTimestamp();
	if (p_amount - withdrawal < 0)
	{
		std::cout	<< " index:" << _accountIndex \
					<< ";p_amount:" << p_amount \
					<< ";withdrawal:refused" << std::endl;
		return true;
	}
	_amount = p_amount - withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout	<< " index:" << _accountIndex \
				<< ";p_amount:" << p_amount \
				<< ";withdrawal:" << withdrawal \
				<< ";amount:" << _amount \
				<< ";nb_withdrawals:" << _nbWithdrawals \
				<< std::endl;
	return true;
}

// std::cout << "[19920104_091532]"; // USING diff 
void Account::_displayTimestamp( void )
{
	char buf[16];
	time_t now;
	time(&now);
	std::strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", localtime(&now));
	std::cout << "[" << buf << "]";
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << checkAmount() \
				<< ";deposits:" << _nbDeposits \
				<< ";withdrawals:" << _nbWithdrawals \
				<< std::endl;
}