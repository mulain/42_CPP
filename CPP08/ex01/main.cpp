/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:42:02 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/04 17:36:06 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Span.hpp"

int main (void)
{
	std::string	partition(70, '-');

	std::cout << partition << std::endl;
	std::cout << "Part 0: Subject test" << std::endl;
	std::cout << partition << std::endl;
 	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << partition << std::endl;
	std::cout << "Part 1: Empty span object" << std::endl;
	std::cout << partition << std::endl;
	Span	span1;
	try
	{
		std::cout << "Longest span of span1: " << span1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "Shortest span of span1: " << span1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << partition << std::endl;
	std::cout << "Part 2: Small span object with overflow" << std::endl;
	std::cout << partition << std::endl;
	for (int i = 0; i < 12; i++)
	{
		try
		{
			span1.addNumber(i);
			std::cout << "Added " << i << " to span1. ";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Longest span: " << span1.longestSpan() << ".";
			std::cout << " Shortest span: " << span1.shortestSpan() << "." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}		
	}
	std::cout << partition << std::endl;
	std::cout << "Part 3: Big span seeded with random numbers using iterator range of a vector" << std::endl;
	std::cout << partition << std::endl;
	
	Span bigboiii(25000);
	std::vector<int> seedvector;
	
	srand(time(NULL));
	for (int i = 0; i < 25000; i++)
		seedvector.push_back(rand());

	bigboiii.addSpan(seedvector.begin(), seedvector.end());
	std::cout << "Longest span: " << bigboiii.longestSpan() << ".";
	std::cout << " Shortest span: " << bigboiii.shortestSpan() << "." << std::endl;
	
	return 0;
}