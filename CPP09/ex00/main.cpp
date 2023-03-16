/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 12:40:22 by wmardin          ###   ########.fr       */
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

int main (int argc, char** argv)
{
	Date date1(2025, 2, 28);
	Date date2(2025, 2, 28);
	BitcoinExchange	mtgox("mtgox");
	if (argc < 2)
	{
		exit(1);
	}
	
	

	mtgox.importData(argv[1]);
	//mtgox.printPairs();
    /* std::map<int, double> asset_prices; // Map to store asset prices by date

    // Inserting some sample data
    asset_prices.insert(std::make_pair(20220101, 50.0));
    asset_prices.insert(std::make_pair(20220102, 60.0));
    asset_prices.insert(std::make_pair(20220103, 70.0));

    // Retrieving the price of an asset on a particular date
    int date = 20220102;
    double price = asset_prices[date];
    std::cout << "The price of the asset on " << date << " is " << price << std::endl;
 */
    return 0;
}
