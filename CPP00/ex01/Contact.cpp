/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:39:34 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/03 14:39:26 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void	Contact::add_contact(std::string input)
{
	this->_index = this->_nbContacts++;
	set_firstname();
}

std::string	Contact::get_input(void)
{
	std::string		input;
	while (1)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (input.empty())
			std::cout << E_BLANK << std::endl;
		else
			break;
	}
	return (input);
}

void	Contact::set_firstname(void)
{
	std::cout << "Enter first name: ";
	this->_firstname = get_input();
}

void	Contact::set_lastname(void)
{
	std::cout << "Enter last name: ";
	this->_lastname = get_input();
}

void	Contact::set_nickname(void)
{
	std::cout << "Enter last name: ";
	this->_nickname = get_input();
}

void	Contact::set_phonenumber(void)
{
	std::cout << "Enter last name: ";
	this->_phonenumber = get_input();
}

void	Contact::set_darkestsecret(void)
{
	std::cout << "Enter last name: ";
	this->_darkestsecret = get_input();
}