#include "Account.hpp"
#include <iostream>

int		Account::getNbAccounts( void ) { return Account::_nbAccounts; }
int		Account::getTotalAmount( void ) { return Account::_totalAmount; }
int		Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }
int		Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:"<< getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) {
	_displayTimestamp();
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account( void ) {
	Account::_nbAccounts++;
	this->_accountIndex = Account::_nbAccounts - 1;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals = 0;

void Account::makeDeposit( int deposit ) {
	int p_amount = this->_amount;
	
	_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;

	std::cout << "index:" << this->_accountIndex <<  ";p_amount:" << p_amount << ";deposit:" << deposit << 
	";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	int	p_amount = this->_amount;
	
	_displayTimestamp();
	if (this->_amount - withdrawal >= 0) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << "index:" << this->_accountIndex <<  ";p_amount:" << p_amount << ";withdrawal:" << withdrawal << 
		";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	std::cout << "index:" << this->_accountIndex <<  ";p_amount:" << p_amount << ";withdrawal:refused" << std::endl;
	return false;
}

int Account::checkAmount( void ) const {
	return this->_amount;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void ) {
	std::cout << "[19920104_091532] ";
}