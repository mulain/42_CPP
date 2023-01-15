/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:41:04 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/15 19:48:04 by wmardin          ###   ########.fr       */
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

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs._name + "_copy";
	this->_attackdmg = rhs._attackdmg;
	this->_energypoints = rhs._energypoints;
	this->_hitpoints = rhs._hitpoints;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " was destroyed!" << std::endl;
}

void	ClapTrap::status(void)
{
	std::cout << "Trap " << _name << " status:" << std::endl;
	std::cout << "Hit points:\t" << _hitpoints << std::endl;
	std::cout << "Energy points:\t" << _energypoints << std::endl;
	std::cout << "Attack damage:\t" << _attackdmg << std::endl;
}

bool	ClapTrap::isActive(void)
{
	if (_hitpoints < 1)
	{
		std::cout << "Trap " << _name << " is ded and can't act!" << std::endl;
		return (false);
	}
	if (_energypoints < 1)
	{
		std::cout << "Trap " << _name << " has no energy points and can't act!" << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->isActive())
		return;
	_energypoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackdmg << " points of damage! ";
	std::cout << _name << " now has " << _energypoints << " energy points left." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	bool alrdyDed;

	if (_hitpoints < 1)
		alrdyDed = true;
	else
		 alrdyDed = false;
	_hitpoints -= amount;
	std::cout << "Trap " << _name << " takes " << amount << " damage, reducing its hit points to " << _hitpoints << "!" << std::endl;
	if (_hitpoints < 1)
	{
		if (alrdyDed)
			std::cout << "Wow. Trap " << _name << " was already ded. Just wow." << std::endl;
		else
			std::cout << "Trap " << _name << " is fatally wounded!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->isActive())
		return;
	_hitpoints += amount;
	_energypoints--;
	std::cout << "Trap " << _name << " was repaired for " << amount << " hit points and now has " << _hitpoints << " hit points! ";
	std::cout << _name << " now has " << _energypoints << " energy points left." << std::endl;
}