/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:32:17 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/11 12:46:01 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):
	_name(name),
	_weapon(weapon)
{
	std::cout << this->_name << " has spawned." << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->_name << " has left the arena." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << '.' << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}