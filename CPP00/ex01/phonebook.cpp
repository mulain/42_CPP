/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:36:25 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/03 19:41:17 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_nbContacts = 0;
	this->_index = 0;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

bool	PhoneBook::empty(void)
{
	return(this->_nbContacts == 0);
}

void	PhoneBook::add_contact(void)
{
	this->_contacts[this->_index].add();
	++this->_index %= BOOKSIZE;
	if (this->_nbContacts <= BOOKSIZE)
		this->_nbContacts++;
}

void	PhoneBook::display_toc(void)
{
	// Display header row
	std::cout << '|' << std::setw(10) << std::right << "index";
	std::cout << '|' << std::setw(10) << std::right << "first name";
	std::cout << '|' << std::setw(10) << std::right << "last name";
	std::cout << '|' << std::setw(10) << std::right << "nick name";
	std::cout << '|' << std::endl;
	// Display contact rows
	for (int i = 0; i < BOOKSIZE; i++)
	{
		if (this->_contacts[i].empty())
			return;
		std::cout << '|' << std::setw(10) << std::right << i;
		std::cout << '|' << std::setw(10) << std::right << this->_contacts->get_firstname();
		std::cout << '|' << std::setw(10) << std::right << this->_contacts->get_lastname();
		std::cout << '|' << std::setw(10) << std::right << this->_contacts->get_nickname();
		std::cout << '|' << std::endl;
	}
}

int	PhoneBook::select_contact()
{
	std::string		input;
	int				ret_val;
	char			*inval;

	while (1)
	{
		std::cout << "Enter index of contact to display: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (input.empty())
			std::cout << E_BLANK << std::endl;
		else
		{
			ret_val = (int)strtol(input.c_str(), &inval, 10);
			if (ret_val > -1 && ret_val < BOOKSIZE  && !*inval)
				break;
			std::cout << E_INVAL << BOOKSIZE - 1 << std::endl;
		}
	}
	return (ret_val);
}

void	PhoneBook::display_contact(int index)
{
	if (this->_contacts[index].empty())
		std::cout << E_INDEXEMPTY << std::endl;
	else
		this->_contacts[index].display();
}