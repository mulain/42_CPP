/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:41:04 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/11 20:26:29 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoints(10), _energypoints(10), _attackdmg(0)
{
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " was destroyed!" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energypoints)
	{
		_energypoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackdmg << " points of damage! ";
		std::cout << _name << " now has " << _energypoints << " energy points left." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " has no energy points left and can't attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitpoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, reducing its hit points to " << _hitpoints << "!" << std::endl;
	if (_hitpoints < 1)
	{
		this->~ClapTrap();
		return;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energypoints)
	{
		_hitpoints += amount;
		_energypoints--;
		std::cout << "ClapTrap " << _name << " was repaired for " << amount << " hit points and now has " << _hitpoints << " hit points! ";
		std::cout << _name << " now has " << _energypoints << " energy points left." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " has no energy points left and can't repair itself!" << std::endl;
}