/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:39:11 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 14:15:10 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(void):
	_year(1),
	_month(1),
	_day(1)
{}

Date::~Date(void)
{}

Date::Date(int year, int month, int day)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

Date::Date(const Date& src)
{
	*this = src;
}

// Operator overloads
Date& Date::operator=(const Date& src)
{
	_year = src._year;
	_month = src._month;
	_day = src._day;
	return *this;
}

bool Date::operator>(const Date &rhs) const
{
	if (_year > rhs._year)
		return true;
	if (_year < rhs._year)
		return false;
	if (_month > rhs._month)
		return true;
	if (_month < rhs._month)
		return false;
	if (_day > rhs._day)
		return true;
	return false;
}

bool Date::operator<(const Date &rhs) const
{
	if (_year < rhs._year)
		return true;
	if (_year > rhs._year)
		return false;
	if (_month < rhs._month)
		return true;
	if (_month > rhs._month)
		return false;
	if (_day < rhs._day)
		return true;
	return false;
}

bool Date::operator==(const Date &rhs) const
{
	return _year == rhs._year && _month == rhs._month && _day == rhs._day;
}

bool Date::operator!=(const Date &rhs) const
{
	return !(*this == rhs);
}

// Setters
bool Date::parseDate(std::string input)
{
	size_t delim = input.find('-');
	if (delim == std::string::npos)
		return false;
	if (!parseYear(input.substr(0, delim).c_str()))
		return false;
	input.erase(0, delim + 1);
	
	delim = input.find('-');
	if (delim == std::string::npos)
		return false;
	if (!parseMonth(input.substr(0, delim).c_str()))
		return false;
	input.erase(0, delim + 1);
	
	if (!parseDay(input.c_str()))
		return false;
	return true;
}

bool Date::parseYear(const char* input)
{
	long	num;
	char*	endptr;

	num = strtol(input, &endptr, 10);
	if (num < INT_MIN || num > INT_MAX || *endptr != 0)
		return false;
	return setYear(num);;
}

bool Date::setYear(int year)
{
	if (year < 1 || year > 9999)
		return _year = -1, false;
	return _year = year, true;
}

bool Date::parseMonth(const char* input)
{
	long	num;
	char*	endptr;

	num = strtol(input, &endptr, 10);
	if (num < INT_MIN || num > INT_MAX || *endptr != 0)
		return false;
	return setMonth(num);
}

bool Date::setMonth(int month)
{
	if (month < 1 || month > 12)
		return _month = -1, false;
	return _month = month, true;
}

bool Date::parseDay(const char* input)
{
	long	num;
	char*	endptr;

	num = strtol(input, &endptr, 10);
	if (num < INT_MIN || num > INT_MAX || *endptr != 0)
		return false;
	return setDay(num);
}

bool Date::setDay(int day)
{
	if (day < 1 || day > 31)
		return _day = -1, false;
	if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
	{
		if (day > 30)
			return _day = -1, false;
	}
	else if (_month == 2)
	{
		if (isLeapYear())
		{
			if (day > 29)
				return day = -1, false;
		}
		else if (day > 28)
			return day = -1, false;
	}
	return _day = day, true;
}

// Helpers
bool Date::isLeapYear() const
{
	return ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0);
}

// Getters
int Date::getYear() const
{
	return _year;
}

int Date::getMonth() const
{
	return _month;
}

int Date::getDay() const
{
	return _day;
}

std::ostream& operator<<(std::ostream& o, const Date& date)
{
	std::cout << std::setw(4) << std::setfill('0') << date.getYear() << '-';
	std::cout << std::setw(2) << std::setfill('0') << date.getMonth() << '-';
	std::cout << std::setw(2) << std::setfill('0') << date.getDay();
	return o;
}
