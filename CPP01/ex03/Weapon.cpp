/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:17:42 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/10 13:24:16 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type):
	_type(type)
{
	std::cout << "A " << type << " was dropped in the arena!" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "A " << this->_type << " was destroyed." << std::endl;
}

const std::string&	Weapon::getType(void) const
{
	const std::string&	typeREF = this->_type;
	return(typeREF);
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}