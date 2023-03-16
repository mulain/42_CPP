/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:39:11 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 16:46:13 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Date.hpp"

BitcoinExchange::BitcoinExchange(void):
	_name("unnamed")
{}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(std::string name):
	_name(name)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

// Operator overloads
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	_name = src._name + "_copy";
	// copy price data ofc
	return *this;
}

// Public functions
void BitcoinExchange::importPriceHistory(char* filepath)
{
	std::ifstream infile(filepath);
	std::string	line;
	Date date;
	double price;

	if (!infile.is_open())
		throw std::range_error(E_INFILE_DB);		
	while (std::getline(infile, line))
	{
		size_t delim = line.find(',');
		if (delim == std::string::npos)
			continue;
		if (!date.parseDate(line.substr(0, delim)))
			continue;
		if (!parsePrice(line.substr(delim + 1, line.size()), &price))
			continue;
		_btc_price.insert(std::make_pair(date, price));
	}
	infile.close();
	std::cout << "Imported " << _btc_price.size() << " valid date-price pairs from database file \"" << filepath << "\"." << std::endl;
}

void BitcoinExchange::printPriceHistory()
{
	for (mapiter it = _btc_price.begin(); it != _btc_price.end(); it++)
		std::cout << it->first << " | " << it->second << std::endl;
}

void BitcoinExchange::importAccountFile(char* filepath)
{
	std::ifstream infile(filepath);
	std::string	line;
	Date date;
	double amount;

	if (!infile.is_open())
		throw std::range_error(E_INFILE_ACC);		
	while (std::getline(infile, line))
	{
		size_t delim = line.find(" |");
		if (delim == std::string::npos)
			continue;
		if (!date.parseDate(line.substr(0, delim)))
			continue;
		if (!parsePrice(line.substr(delim + 3, line.size()), &amount))
			continue;
		_btc_amount.insert(std::make_pair(date, amount));
	}
	infile.close();
	std::cout << "Imported " << _btc_amount.size() << " valid date-amount pairs from account file \"" << filepath << "\"." << std::endl;
}

void BitcoinExchange::printAccountFile()
{
	std::cout << "Account file in BTC exchange " << _name << ":" << std::endl;
	std::cout << std::setw(11) << std::setfill(' ') << std::left << "Date" << "| Amount" << std::endl;
	for (m_mapiter it = _btc_amount.begin(); it != _btc_amount.end(); it++)
		std::cout << it->first << " | " << it->second << std::endl;
}

void BitcoinExchange::printAccountOverview()
{
	std::cout << "Account overview in BTC exchange " << _name << ":" << std::endl;
	std::cout << std::setfill(' ') << std::left;
	std::cout << std::setw(11) << "Date";
	std::cout << std::setw(11) << "| Amnt BTC";
	std::cout << std::setw(11) << "| Price";
	std::cout << std::setw(11) << "| Value" << std::endl;
	for (m_mapiter it = _btc_amount.begin(); it != _btc_amount.end(); it++)
	{
		std::cout << it->first << " | ";
		std::cout << std::setfill(' ');
		std::cout << std::setw(8) << it->second << " | ";
		std::cout << std::setw(8) << getPriceOnDate(it->first) << " | ";
		std::cout << std::setw(8) << getPriceOnDate(it->first) * it->second; 
		std::cout << std::endl;
	}
}

double	BitcoinExchange::getPriceOnDate(Date date)
{
	mapiter it = _btc_price.begin();
	while (it->first <= date && it !=_btc_price.end())
		it++;
	if (it == _btc_price.begin())
		return std::numeric_limits<double>::quiet_NaN();
	return (--it)->second;
}

std::string BitcoinExchange::getName()
{
	return _name;
}

// Private functions
bool BitcoinExchange::parsePrice(std::string input, double* num)
{
	char*	endptr;

	*num = strtod(input.c_str(), &endptr);
	if (*num < 0 || *num > INT_MAX || *endptr != 0)
		return false;
	return true;
}

bool BitcoinExchange::parseAmount(std::string input, double* num)
{
	char*	endptr;

	*num = strtod(input.c_str(), &endptr);
	if (*num < 0 || *num > 1000 || *endptr != 0)
		return false;
	return true;
}

