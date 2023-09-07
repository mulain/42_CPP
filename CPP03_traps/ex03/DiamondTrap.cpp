/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:38 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 18:00:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	_name("Nameless")
{
	std::cout << "Unnamed DiamondTrap created." << std::endl;
	_hitpoints = FragTrap::_hitpoints;
	_energypoints = ScavTrap::_energypoints;
	_attackdmg = FragTrap::_attackdmg;
	ClapTrap::_name = _name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string name):
	_name(name)
{
	_hitpoints = FragTrap::_hitpoints;
	_energypoints = ScavTrap::_energypoints;
	_attackdmg = FragTrap::_attackdmg;
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "DiamondTrap " << _name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src): ClapTrap(), ScavTrap(), FragTrap()
{
	*this = src;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->_name = rhs._name + "_copy";
	_attackdmg = rhs._attackdmg;
	_energypoints = rhs._energypoints;
	_hitpoints = rhs._hitpoints;
	ClapTrap::_name = _name + "_clap_name";
	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " was destroyed!" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My street name is " << _name << ", but my full Clap name is: " << ClapTrap::_name << std::endl;
}