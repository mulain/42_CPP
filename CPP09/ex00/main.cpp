/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 14:50:22 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
You have to create a program which outputs the value of a certain amount of bitcoin
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
• A valid value must be either a float or a positive integer between 0 and 1000.
 */


#include <iostream>
#include <map>
#include <utility>

#include "Date.hpp"
#include "BitcoinExchange.hpp"

#define E_INPUTFILE	"Please provide an input file."

int main (int argc, char** argv)
{
	Date date0(2008, 1, 1);
	Date date1(2025, 2, 28);
	Date date2(2020, 1, 1);
	Date date3(2020, 1, 2);
	Date date4(1900, 1, 1);
	BitcoinExchange	mtgox("mtgox");
	
	if (argc < 2)
	{
		std::cout << E_INPUTFILE << std::endl;
		exit(1);
	}
	mtgox.importData((char*)"data.csv");
	std::cout << "Reading input file: " << argv[1] << std::endl;
	std::cout << date0 << ": " << mtgox.getPriceOnDate(date0) << std::endl;
	std::cout << date1 << ": " << mtgox.getPriceOnDate(date1) << std::endl;
	std::cout << date2 << ": " << mtgox.getPriceOnDate(date2) << std::endl;
	std::cout << date3 << ": " << mtgox.getPriceOnDate(date3) << std::endl;
	std::cout << date4 << ": " << mtgox.getPriceOnDate(date4) << std::endl;
    return 0;
}
