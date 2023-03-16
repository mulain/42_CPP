/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:39:11 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 13:56:38 by wmardin          ###   ########.fr       */
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
		throw std::range_error("Could not open input file.");		
	while (std::getline(infile, line))
	{
		size_t delim = line.find(',');
		if (delim == std::string::npos)
			continue;
		if (!parseDate(line.substr(0, delim), &date))
			continue;
		if (!parsePrice(line.substr(delim + 1, line.size()), &price))
			continue;
		_btc_price.insert(std::make_pair(date, price));
	}
	infile.close();
	std::cout << "Parsed file: " << input << std::endl;
	std::cout << "Imported pairs: " << _btc_price.size() << std::endl;
}

void BitcoinExchange::printPairs()
{
	for (std::map<Date, double>::const_iterator it = _btc_price.begin(); it != _btc_price.end(); it++)
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}
}

// Private functions
bool BitcoinExchange::parseDate(std::string input, Date* date)
{
	size_t	delim;
	long	year;
	long	month;
	long	day;

	// parse year
	delim = input.find('-');
	if (delim == std::string::npos)
		return false;
	if (!parseYear(input.substr(0, delim).c_str(), &year))
		return false;
	input.erase(0, delim + 1);
	
	// parse month
	delim = input.find('-');
	if (delim == std::string::npos)
		return false;
	if (!parseMonth(input.substr(0, delim).c_str(), &month))
		return false;
	input.erase(0, delim + 1);

	// parse day
	if (!parseDay(input.c_str(), &day, year, month))
		return false;
	
	//clean this shite up! just return false on date creation
	date->setYear(static_cast<int>(year));
	date->setMonth(static_cast<int>(month));	
	date->setDay(static_cast<int>(day));
	return true;
}

bool BitcoinExchange::parseYear(const char* input, long* year)
{
	char*	endptr;

	*year = strtol(input, &endptr, 10);
	if (*year < 1 || *year > 9999 || *endptr != 0)
		return false;
	return true;
}

bool BitcoinExchange::parseMonth(const char* input, long* month)
{
	char*	endptr;

	*month = strtol(input, &endptr, 10);
	if (*month < 1 || *month > 12 || *endptr != 0)
		return false;
	return true;
}

bool BitcoinExchange::parseDay(const char* input, long* day, int year, int month)
{
	char*	endptr;

	*day = strtol(input, &endptr, 10);
	if (*day < 1 || *day > 31 || *endptr != 0)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (*day > 30)
			return false;
	}
	else if (month == 2)
	{
		if (isLeapYear(year))
		{
			if (*day > 29)
				return false;
		}
		else if (*day > 28)
			return false;
	}
	return true;
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

bool BitcoinExchange::parsePrice(std::string input, double* price)
{
	char*	endptr;

	*price = strtod(input.c_str(), &endptr);
	if (*price < 0 || *endptr != 0)
		return false;
	return true;
}
