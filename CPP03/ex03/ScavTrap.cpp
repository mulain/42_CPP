/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:26:45 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/15 19:52:12 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	_hitpoints = 100;
	_energypoints = 50;
	_attackdmg = 20;
	std::cout << "Unnamed ScavTrap created." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_hitpoints = 100;
	_energypoints = 50;
	_attackdmg = 20;
	std::cout << "ScavTrap " << _name << " created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap()
{
	*this = src;
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_name = rhs._name + "_copy";
	this->_attackdmg = rhs._attackdmg;
	this->_energypoints = rhs._energypoints;
	this->_hitpoints = rhs._hitpoints;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " was destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!this->isActive())
		return;
	_energypoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackdmg << " points of damage! ";
	std::cout << _name << " now has " << _energypoints << " energy points left." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (!this->isActive())
		return;
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}
