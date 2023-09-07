/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:42:02 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/03 22:13:13 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main (void)
{
	std::string	partition(70, '-');

	std::cout << partition << std::endl;
	std::cout << "Part 0: Automatic initialization when using <new> without arguments" << std::endl;
	std::cout << partition << std::endl;
	
	int* a = new int();
	std::cout << *a << std::endl;
	delete a;
	
	std::cout << partition << std::endl;
	std::cout << "Part 1: Initializiation with and without arguments, then trying to print the array" << std::endl;
	std::cout << partition << std::endl;
	
	Array<int>		array_a(5);
	Array<int>		array_b;

	std::cout << "array_a size: " << array_a.getSize() << std::endl;
	try
	{
		for (int i = 0; i < 5; i++)
		std::cout << "array_a element[" << i << "]: " << array_a[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "array_b size: " << array_b.getSize() << std::endl;
	try
	{
		for (int i = 0; i < 5; i++)
		std::cout << "array_b element[" << i << "]: " << array_b[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

 	std::cout << partition << std::endl;
	std::cout << "Part 2: Setting array_a element 1 to value of 42, then trying with array_b" << std::endl;
	std::cout << partition << std::endl;
	
	array_a[1] = 42;
	try
	{
		for (int i = 0; i < 5; i++)
		std::cout << "array_a element[" << i << "]: " << array_a[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		array_b[1] = 42;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << partition << std::endl;
	std::cout << "Part 3: Copying array_a to array_b" << std::endl;
	std::cout << partition << std::endl;

	array_b = array_a;
	for (int i = 0; i < 5; i++)
		std::cout << "array_b element[" << i << "]: " << array_b[i] << std::endl;
	
	std::cout << partition << std::endl;
	std::cout << "Part 4: Modifying array_a (element 0 to 420); array_b is unaffected" << std::endl;
	std::cout << partition << std::endl;

	array_a[0] = 420;

	for (int i = 0; i < 5; i++)
		std::cout << "array_a element[" << i << "]: " << array_a[i] << std::endl;
	std::cout << partition << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "array_b element[" << i << "]: " << array_b[i] << std::endl;

	std::cout << partition << std::endl;
	std::cout << "Part 4: Copying the smaller array_c (size 1) to array_a (size 5)" << std::endl;
	std::cout << partition << std::endl;

	Array<int>	array_c(1);

	array_a = array_c;
	std::cout << "array_a size: " << array_a.getSize() << std::endl;

	std::cout << partition << std::endl;
	std::cout << "Part 5: Char array also works" << std::endl;
	std::cout << partition << std::endl;

	Array<char> charray_a(5);

	charray_a[0] = 'a';

	std::cout << "charray_a size: " << charray_a.getSize() << std::endl;
	std::cout << "charray_a element 0: " << charray_a[0] << std::endl;
	std::cout << "charray_a element 1 (not manually initialized): " << charray_a[1] << std::endl;
	std::cout << "charray_a element 1 cast to int: " << static_cast<int>(charray_a[1]) << std::endl;
	
	return 0;
}
