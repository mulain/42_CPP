/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:39:11 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 00:28:58 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date(void):
	_year(-1),
	_month(-1),
	_day(-1)
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

Date& Date::operator=(const Date& src)
{
	_year = src._year;
	_month = src._month;
	_day = src._day;
	return *this;
}

std::string Date::getDateString() const
{
	return std::to_string(_year) + "-" + std::to_string(_month) + "-" + std::to_string(_day);
}

// Setters
void Date::setYear(int year)
{
	if (year < 1 || year > 9999)
		throw std::out_of_range("Year out of range.");
	_year = year;
}

void Date::setMonth(int month)
{
	if (month < 1 || month > 12)
		throw std::out_of_range("Month out of range.");
	_month = month;
}

void Date::setDay(int day)
{
	if (day < 1 || day > 31)
		throw std::out_of_range("Day out of range.");
	if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
	{
		if (day > 30)
			throw std::out_of_range("Day out of range.");
	}
	else if (_month == 2)
	{
		if (isLeapYear(_year))
		{
			if (day > 29)
				throw std::out_of_range("Day out of range.");
		}
		else if (day > 28)
			throw std::out_of_range("Day out of range.");
	}
	_day = day;
}

// Helpers
bool Date::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
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
