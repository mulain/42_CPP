/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:36:25 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/30 20:19:25 by wmardin          ###   ########.fr       */
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
	for (int i = 0; i < 5; i++)
	{
		while (this->_contacts[this->_index].fields[i].value.empty())
		{
			std::cout << "Enter " << this->_contacts[this->_index].fields[i].name << ": ";
			std::cin >> this->_contacts[this->_index].fields[i].value;
			std::cin.get();
		}
	}
	++this->_index %= 8;
}