/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:59:13 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/10 13:18:37 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name):
	_name(name),
	_weapon(NULL)
{
	std::cout << this->_name << " has spawned." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " has left the arena." << std::endl;
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << '.' << std::endl;
	else
		std::cout << this->_name << " just flails around weaponlessly.";
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weapon = &weapon;
}