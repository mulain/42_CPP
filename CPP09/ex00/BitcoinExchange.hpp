/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:48:44 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 13:02:19 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <utility>

#include "Date.hpp"

#define E_INFILE	"Infile error."

class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);
		BitcoinExchange(std::string);
		BitcoinExchange(const BitcoinExchange&);

		BitcoinExchange& operator=(const BitcoinExchange&);

		void importData(char*);
		void printPairs();
		

		
		float getPrice(std::string);
	
	private:
		bool parseDate(std::string, Date*);
		bool parseYear(const char*, long*);
		bool parseMonth(const char*, long*);
		bool parseDay(const char*, long*, int, int);
		bool isLeapYear(int) const;
		bool parsePrice(std::string, double*);
		
		std::string				_name;
		std::map<Date, double> _btc_price;
};

#endif