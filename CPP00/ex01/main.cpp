/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 11:22:08 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/31 14:57:32 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void error_emptyinput(std::string);

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
			phonebook.display_toc();
		}
		else
			std::cout << "phonebook: invalid command." << std::endl;

		input.clear();
	}
}