/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:39:11 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/15 22:39:20 by wmardin          ###   ########.fr       */
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

Date::Date(int year, int month, int day):
	_year(year),
	_month(month),
	_day(day)
{}

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
