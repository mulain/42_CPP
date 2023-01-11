/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:41:04 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/11 21:30:41 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_name("Nameless"),
	_hitpoints(10),
	_energypoints(10),
	_attackdmg(0)
{
	std::cout << "Unnamed ClapTrap created." << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hitpoints(10),
	_energypoints(10),
	_attackdmg(0)
{
	std::cout << "ClapTrap " << _name << " created." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " was destroyed!" << std::endl;
}

void	ClapTrap::status(void)
{
	std::cout << "ClapTrap " << _name << " status:" << std::endl;
	std::cout << "Hit points:\t" << _hitpoints << std::endl;
	std::cout << "Energy points:\t" << _energypoints << std::endl;
	std::cout << "Attack damage:\t" << _attackdmg << std::endl;
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
	if (_hitpoints < 1)
		std::cout "Wow. They already ded..." << std::endl;
	_hitpoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, reducing its hit points to " << _hitpoints << "!" << std::endl;
	if (_hitpoints < 1)
		std::cout << "ClapTrap " << _name << " is fatally wounded!" << std::endl;
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