/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:48:44 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 15:14:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <limits>

#include "Date.hpp"

#define E_INFILE_DB		"Infile error: price history database."
#define E_INFILE_ACC	"Infile error: account history file."

typedef std::map<Date, double>::const_iterator	mapiter;

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(std::string);
		BitcoinExchange(const BitcoinExchange&);

		BitcoinExchange& operator=(const BitcoinExchange&);

		void importPriceHistory(char*);
		void printPriceHistory();
		void importAccountFile(char*);
		double getPriceOnDate(Date);
	
	private:
		bool parseDate(std::string, Date*);
		bool parseYear(const char*, long*);
		bool parseMonth(const char*, long*);
		bool parseDay(const char*, long*, int, int);
		bool isLeapYear(int) const;
		bool parsePrice(std::string, double*);
		
		std::string				_name;
		std::map<Date, double> _btc_price;
		std::map<Date, double> _btc_amount;
};

#endif