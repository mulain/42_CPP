/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:39:11 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 14:51:46 by wmardin          ###   ########.fr       */
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
void BitcoinExchange::importData(char* input)
{
	std::ifstream infile(input);
	std::string	line;
	Date date;
	double price;

	if (!infile.is_open())
		throw std::range_error(E_INFILE);		
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
	std::cout << "Imported database file: " << input << std::endl;
	std::cout << "Imported valid pairs: " << _btc_price.size() << std::endl;
}

void BitcoinExchange::printPairs()
{
	for (mapiter it = _btc_price.begin(); it != _btc_price.end(); it++)
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}
}

double	BitcoinExchange::getPriceOnDate(Date date)
{
	mapiter it = _btc_price.begin();
	while (it->first <= date && it !=_btc_price.end())
		it++;
	if (it == _btc_price.begin())
		return 0;
	return (--it)->second;
}

// Private functions
bool BitcoinExchange::parsePrice(std::string input, double* price)
{
	char*	endptr;

	*price = strtod(input.c_str(), &endptr);
	if (*price < 0 || *price > INT_MAX || *endptr != 0)
		return false;
	return true;
}
