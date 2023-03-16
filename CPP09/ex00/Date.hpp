/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:48:44 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 14:03:39 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* You have to create a program which outputs the value of a certain amount of bitcoin
on a certain date.

This program must use a database in csv format which will represent bitcoin price
over time. This database is provided with this subject.

The program will take as input a second database, storing the different prices/dates
to evaluate.

Your program must respect these rules:
• The program name is btc.
• Your program must take a file as argument.
• Each line in this file must use the following format: "date | value".
• A valid date will always be in the following format: Year-Month-Day.
• A valid value must be either a float or a positive integer between 0 and 1000. */

#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdlib>

class Date
{
	public:
		Date(void);
		~Date(void);
		Date(int, int, int);
		Date(const Date&);

		Date& operator=(const Date&);
		bool operator<(const Date&) const;
		bool operator>(const Date&) const;
		bool operator==(const Date &rhs) const;
		bool operator!=(const Date &rhs) const;

		bool parseDate(std::string);
		
		bool parseYear(const char*);
		bool setYear(int);
		
		bool parseMonth(const char*);
		bool setMonth(int);

		bool parseDay(const char*);
		bool setDay(int);
		
		int getYear() const;
		int getMonth() const;
		int getDay() const;

	private:
		bool isLeapYear() const;
		
		int _year;
		int _month;
		int _day;		
};

std::ostream& operator<<(std::ostream& o, const Date& date);

#endif
