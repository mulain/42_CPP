/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/20 11:10:19 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"
#include "BitcoinExchange.hpp"

int main (int argc, char** argv)
{
	std::string partition(70, '-');

	if (argc < 2)
	{
		std::cout << "Please provide an input file." << std::endl;
		exit(1);
	}
	{
		std::cout << partition << std::endl;
		std::cout << "Scope 0: Date range tests" << std::endl;
		std::cout << partition << std::endl;
	
		Date date0(2008, 1, 1);
		Date date1(2025, 2, 28);
		Date date2(2020, 1, 1);
		Date date3(2020, 1, 2);
		Date date4(1900, 1, 1);
		BitcoinExchange	mtgox("mtgox");

		mtgox.importPriceHistory((char*)"data.csv");
		mtgox.importAccountFile(argv[1]);
		std::cout << date4 << ": " << mtgox.getPriceOnDate(date4) << std::endl;
		std::cout << date0 << ": " << mtgox.getPriceOnDate(date0) << std::endl;
		std::cout << date2 << ": " << mtgox.getPriceOnDate(date2) << std::endl;
		std::cout << date3 << ": " << mtgox.getPriceOnDate(date3) << std::endl;
		std::cout << date1 << ": " << mtgox.getPriceOnDate(date1) << std::endl;

		mtgox.printAccountFile();

		BitcoinExchange poloniex("poloniex");

		poloniex.printAccountOverview();
		poloniex = mtgox;
		poloniex.printAccountOverview();
	}
	{
		std::cout << partition << std::endl;
		std::cout << "Scope 1: shmismshmang" << std::endl;
		std::cout << partition << std::endl;

		BitcoinExchange	mtgox("mtgox");

		mtgox.importPriceHistory((char*)"data.csv");
		mtgox.importAccountFile(argv[1]);
		mtgox.printAccountOverview();
	}
	
}
