/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:45:57 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/05 23:19:59 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name):
	_name(name)
{
	std::cout << this->_name << " sprang to unlife!" << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << "A zombie has sprung to unlife!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " dieded." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}