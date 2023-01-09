/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:17:42 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/09 17:47:31 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type):
	_type(type)
{
return;
}

Weapon::~Weapon(void)
{
	std::cout << this->_type << " destroyed." << std::endl;
}

const std::string&	Weapon::getType(void)
{
	const std::string&	typeREF = this->_type;
	return(typeREF);
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}