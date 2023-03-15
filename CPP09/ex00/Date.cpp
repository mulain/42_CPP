/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:39:11 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/15 21:57:52 by wmardin          ###   ########.fr       */
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

std::string Date::getDateString()
{
	std::string dateString;

	dateString = std::to_string(_year) + "-" + std::to_string(_month) + "-" + std::to_string(_day);
	//dateString = _year + "-" + _month + "-" + _day;
	return dateString;
}
