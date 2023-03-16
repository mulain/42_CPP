/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:39:11 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 10:22:20 by wmardin          ###   ########.fr       */
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
void Date::setYear(int year)
{
	if (year < 1 || year > 9999)
		throw std::out_of_range("Year out of range: 1 to 9999 valid.");
	_year = year;
}

void Date::setMonth(int month)
{
	if (month < 1 || month > 12)
		throw std::out_of_range("Month out of range: 1 to 12 valid.");
	_month = month;
}

void Date::setDay(int day)
{
	if (day < 1 || day > 31)
		throw std::out_of_range("Day out of range: 1 to 31 valid for that month.");
	if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
	{
		if (day > 30)
			throw std::out_of_range("Day out of range: 1 to 30 valid for that month.");
	}
	else if (_month == 2)
	{
		if (isLeapYear())
		{
			if (day > 29)
				throw std::out_of_range("Day out of range: 1 to 29 valid for February in a leap year.");
		}
		else if (day > 28)
			throw std::out_of_range("Day out of range: 1 to 28 valid for February in a non leap year.");
	}
	_day = day;
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
