/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:42:02 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/02 10:42:45 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

int main (void)
{
	std::string	partition(50, '-');
	char		chars[5] = {'a', 'b', 'c', 'd', 0};
	int			ints[5] = {2, 3, 5, 7, 11};
	char*		charptrs[5];
	int*		intptrs[5];

	for (int i = 0; i < 5; i++)
	{
		charptrs[i] = &chars[i];
		intptrs[i] = &ints[i];
	}
	
	iter(chars, 5, print);
	std::cout << partition << std::endl;
	
	iter(ints, 5, print);
	std::cout << partition << std::endl;
	
	iter(charptrs, 5, print);
	std::cout << partition << std::endl;
	
	iter(intptrs, 5, print);
	std::cout << partition << std::endl;
	
	iter(ints, 5, increment);	
	iter(ints, 5, print);

	return 0;
}
