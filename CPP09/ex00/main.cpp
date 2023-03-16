/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/16 01:01:16 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <utility>

#include "Date.hpp"

int main (void)
{
	Date	date1(2025, 2, 28);
	Date	date2(2026, 1, 29);

	std::cout << date1 << std::endl;

	std::cout << date2 << " is < " << date1 << ": " << (date2 < date1 ? "true" : "false") << std::endl;
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
