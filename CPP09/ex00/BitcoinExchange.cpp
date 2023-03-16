/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:39:11 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 10:28:36 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void):
	_name("unnamed")
{}

BitcoinExchange::~BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(std::string name):
	_name(name)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	_name = src._name + "_copy";
	// copy price data ofc
	return *this;
}

void BitcoinExchange::importData(char* input)
{
	std::ifstream	infile(input);
	std::string		line;

	if (!infile.is_open())
		throw std::range_error("Could not open input file.");
	while (std::getline(infile, line))
	{
		
	}
	infile.close();
	
}