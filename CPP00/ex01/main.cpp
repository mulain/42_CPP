/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:22:08 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/30 10:35:00 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	std::string		input;
	//PhoneBook		phonebook;

	while (1)
	{
		std::cout << "Enter command (<ADD>, <SEARCH> or <EXIT>)" << std::endl;
		if (std::cin.eof())
			break;
		std::getline(std::cin, input);
		if (!input.compare("ADD"))
			std::cout << "Add stuff" << std::endl;
		else if (!input.compare("SEARCH"))
			std::cout << "compare stuff" << std::endl;
		else if (!input.compare("EXIT"))
			break;
		else
			std::cout << "phonebook: invalid command." << std::endl;
		input.clear();
	}
}

/* if (input.empty())
		std::cout << E_BLANK << std::endl; */
