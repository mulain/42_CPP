/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:48:44 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/15 21:51:45 by wmardin          ###   ########.fr       */
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
#include <vector>
#include <algorithm>

class Date
{
	public:
		Date(void);
		~Date(void);
		Date(int, int, int);
		Date(const Date&);

		Date& operator=(const Date&);
	
		int getYear();
		int getMonth();
		int getDay();
		//setters? prolly no! Prolly also get rid of getters.
		std::string getDateString();

	private:
		int _year;
		int _month;
		int _day;		
};

#endif
