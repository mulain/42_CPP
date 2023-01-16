/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:53:22 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 11:57:57 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	_hitpoints = 100;
	_energypoints = 100;
	_attackdmg = 30;
	std::cout << "Unnamed FragTrap created." << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	_name = name;
	_hitpoints = 100;
	_energypoints = 100;
	_attackdmg = 30;
	std::cout << "FragTrap " << _name << " created." << std::endl;
}

FragTrap::FragTrap(FragTrap const & rhs): ClapTrap()
{
	*this = rhs;
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	this->_name = rhs._name + "_copy";
	this->_attackdmg = rhs._attackdmg;
	this->_energypoints = rhs._energypoints;
	this->_hitpoints = rhs._hitpoints;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (!isActive())
		return;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackdmg << " points of damage! ";
	std::cout << _name << " now has " << _energypoints << " energy points left." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (!isActive())
		return;
	std::cout << "FragTrap " << _name << " is in a good mood and wants to high five!" << std::endl;
}