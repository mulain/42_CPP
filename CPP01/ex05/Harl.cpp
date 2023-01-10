/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:24:52 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/10 20:53:25 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl has entered the building." << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl has left the building." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	void (Harl::*f_array[4])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*f_array[i])();
			return;
		}
	}
	std::cout << "Unknown level." << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "Harl: debug (lvl 0)" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Harl: info (lvl 1)" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Harl: warning (lvl 2)" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Harl: error (lvl 3)" << std::endl;
}