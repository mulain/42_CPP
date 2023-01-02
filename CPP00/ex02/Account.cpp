/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 11:20:56 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/02 18:45:13 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

/*
Syntax for logfile comparison to omit timestamp outputs
cut -c 17- mylog.log > 2023.log
cmp 1992.log 2023.log
diff -u 1992.log 2023.log > diff.log
*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):
	_accountIndex(this->_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';';
	std::cout << "total:" <<_totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		rawtime;
	tm			*timeinfo;
	char		timeoutput[69];
	char const	*timeformat = "[%G%m%d_%H%M%S] ";

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(timeoutput, 420, timeformat, timeinfo);
	std::cout << timeoutput;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "deposits:" << this->_nbDeposits << ';';
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	std::cout << "deposit:" << deposit << ';';
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ';';
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	this->_totalAmount -= withdrawal;
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}