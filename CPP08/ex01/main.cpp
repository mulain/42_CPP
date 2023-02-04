/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:42:02 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/04 12:17:55 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main (void)
{
	std::string	partition(70, '-');

	std::cout << partition << std::endl;
	std::cout << "Part 0: Instantiating Span objects" << std::endl;
	std::cout << partition << std::endl;

	Span	span1;
	Span	spanbigboiii(10000);

	std::cout << partition << std::endl;
	std::cout << "Part 1: Empty span" << std::endl;
std::cout << partition << std::endl;

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
	return 0;
}
