/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:42:02 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/04 16:50:38 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>

#include "easyfind.hpp"

int main (void)
{
	std::vector<int>	vector1;
	std::string	partition(70, '-');

	std::cout << partition << std::endl;
	std::cout << "Part 1: int vector: value that is present" << std::endl;
	std::cout << partition << std::endl;
	for (int i = 1; i < 11; i++)
		vector1.push_back(i);
	try
	{
		std::cout << *easyFind(vector1, 1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << partition << std::endl;
	std::cout << "Part 2: int vector: value that is not present" << std::endl;
	std::cout << partition << std::endl;
	for (int i = 1; i < 11; i++)
		vector1.push_back(i);
	try
	{
		std::cout << *easyFind(vector1, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
