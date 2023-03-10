/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:22:08 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/02 19:04:43 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	std::string		input;
	PhoneBook		phonebook;

	while (1)
	{
		std::cout << "Enter command (<ADD>, <SEARCH> or <EXIT>)" << std::endl;
		std::getline(std::cin, input);
		if (input.compare("EXIT") == 0 || std::cin.eof())
			exit(0);
		if (input.compare("ADD") == 0)
			phonebook.add_contact();
		else if (input.compare("SEARCH") == 0)
		{
			if (phonebook.empty())
				std::cout << E_BOOKEMPTY << std::endl;
			else
			{
				phonebook.display_toc();
				phonebook.display_contact(phonebook.select_contact());
			}
		}
		else
			std::cout << "phonebook: invalid command." << std::endl;
	}
}