/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 08:36:25 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/02 19:22:53 by wmardin          ###   ########.fr       */
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

bool	PhoneBook::empty(void)
{
	return(this->_contacts[0].fields[0].value.empty());
}

void	PhoneBook::add_contact(void)
{
	std::string		input;

	for (int i = 0; i < 5; i++)
	{
		while (1)
		{
			std::cout << "Enter " << this->_contacts[this->_index].fields[i].name << ": ";
			std::getline(std::cin, input);
			if (std::cin.eof())
				exit(0);
			if (input.empty())
				std::cout << E_BLANK << std::endl;
			else
				break;
		}
		this->_contacts[this->_index].fields[i].value = input;
	}
	++this->_index %= BOOKSIZE;
}

void	PhoneBook::display_toc(void)
{
	// Display header row
	std::cout << '|' << std::setw(10) << std::right << "index";
	for (int i = 0; i < 3; i++)
		std::cout << '|' << std::setw(10) << std::right << this->display_version(this->_contacts[0].fields[i].name);
	std::cout << '|' << std::endl;
	// Display contact rows
	for (int i = 0; i < BOOKSIZE; i++)
	{
		if (this->_contacts[i].fields[0].value.empty())
			break;
		std::cout << '|' << std::setw(10) << std::right << i;
		for (int j = 0; j < 3; j++)
			std::cout << '|' << std::setw(10) << std::right << this->display_version(this->_contacts[i].fields[j].value);
		std::cout << '|' << std::endl;
	}
}

std::string		PhoneBook::display_version(std::string field)
{
	if (field.length() > 10)
	{
		field.resize(9);
		field.append(".");
	}
	return (field);
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
	if (this->_contacts[index].fields[0].value.empty())
	{
		std::cout << E_INDEXEMPTY << std::endl;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << this->_contacts[index].fields[i].name << ": ";
		std::cout << this->_contacts[index].fields[i].value << std::endl;
	}
}