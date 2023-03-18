/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:48:44 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/18 11:13:13 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
#define BTC_HPP

#include <iomanip>
#include <fstream>
#include <map>
#include <limits>

#include "Date.hpp"

#define E_INFILE_DB		"Infile error: price history database."
#define E_INFILE_ACC	"Infile error: account history file."

typedef std::map<Date, double>::const_iterator	mapiter;
typedef std::multimap<Date, double>::const_iterator	m_mapiter;

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
		void printAccountFile();
		void printAccountOverview();
		
		double getPriceOnDate(Date);
		std::string getName() const;
	
	private:
		bool parsePrice(std::string, double*);
		bool parseAmount(std::string, double*);

		std::string					_name;
		std::map<Date, double> 		_btc_price;
		std::multimap<Date, double> _btc_amount;
};

#endif
