/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:42:02 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/03 17:57:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main (void)
{
	std::string	partition(50, '-');

	std::cout << partition << std::endl;
	std::cout << "Part 0: Automatic initialization when using <new> without arguments" << std::endl;
	std::cout << partition << std::endl;
	
	int* a = new int();
	std::cout << *a << std::endl;
	
	std::cout << partition << std::endl;
	std::cout << "Part 1: Initializiation with and without arguments, then trying to print the array" << std::endl;
	std::cout << partition << std::endl;
	
	Array<int>		array_a(5);
	Array<char>		array_b;

	std::cout << "array_a size: " << array_a.getSize() << std::endl;
	try
	{
		for (int i = 0; i < 5; i++)
		std::cout << "array_a element[" << i << "]: " << array_a.getElement(i) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "array_b size: " << array_b.getSize() << std::endl;
	try
	{
		for (int i = 0; i < 5; i++)
		std::cout << "array_b element[" << i << "]: " << array_b.getElement(i) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << partition << std::endl;
	std::cout << "Part 2: Setting array_a element 1 to value of 42, then trying with array_b" << std::endl;
	std::cout << partition << std::endl;
	
	array_a.setElement(1, 42);
	try
	{
		for (int i = 0; i < 5; i++)
		std::cout << "array_a element[" << i << "]: " << array_a.getElement(i) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		array_b.setElement(1, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
