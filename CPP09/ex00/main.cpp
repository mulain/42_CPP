/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/15 19:32:58 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

#include "easyfind.hpp"

int main (void)
{
	std::vector<int>			vector1;
	std::vector<int>::iterator	iter;
	std::string					partition(70, '-');

	std::cout << partition << std::endl;
	std::cout << "Part 1: int vector: value that is present" << std::endl;
	std::cout << partition << std::endl;
	for (int i = 1; i < 11; i++)
		vector1.push_back(i);
	
	iter = easyFind(vector1, 2);
	std::cout << (iter != vector1.end() ? "Value found!" : "Value not found!") << std::endl;
	
	std::cout << partition << std::endl;
	std::cout << "Part 2: int vector: value that is not present" << std::endl;
	std::cout << partition << std::endl;
	
	iter = easyFind(vector1, 42);
	std::cout << (iter != vector1.end() ? "Value found!" : "Value not found!") << std::endl;
	return 0;
}
