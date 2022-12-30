/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:36:25 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/30 21:20:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::add_contact(void)
{
	std::string		input;

	for (int i = 0; i < 5; i++)
	{
		this->_contacts[this->_index].fields[i].value.clear();
		while (this->_contacts[this->_index].fields[i].value.empty())
		{
			std::cout << "Enter " << this->_contacts[this->_index].fields[i].name << ": ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				exit(0);
			if (input.empty())
				std::cout << E_BLANK << std::endl;
			this->_contacts[this->_index].fields[i].value = input;
		}
	}
	std::cout << (int)this->_index << std::endl;
	++this->_index %= 8;
}