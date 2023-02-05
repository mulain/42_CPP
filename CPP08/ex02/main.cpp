/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:42:02 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/05 13:33:22 by wmardin          ###   ########.fr       */
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
	std::cout << "Part 2: Small span object with overflow and a negative number" << std::endl;
	std::cout << partition << std::endl;
	span1.addNumber(-5);
	for (int i = 2; i < 12; i++)
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
	
	std::cout << partition << std::endl;
	std::cout << "Part 4: Big span seeded with overflow" << std::endl;
	std::cout << partition << std::endl;
	
	std::vector<int> seedvector2;
	Span notbigenoughboi(10000);
	
	srand(time(NULL));
	for (int i = 0; i < 250000; i++)
		seedvector2.push_back(rand());
	try
	{
		notbigenoughboi.addSpan(seedvector2.begin(), seedvector2.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
	std::cout << "Longest span: " << notbigenoughboi.longestSpan() << ".";
	std::cout << " Shortest span: " << notbigenoughboi.shortestSpan() << "." << std::endl;
	
	return 0;
}
