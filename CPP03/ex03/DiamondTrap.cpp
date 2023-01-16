/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:38 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 19:51:54 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	_name("Nameless")
{
	std::cout << "Unnamed DiamondTrap created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	_name(name)
{
	std::cout << "DiamondTrap " << _name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	*this = src;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->_name = rhs._name + "_copy";
	/* this->_attackdmg = rhs._attackdmg;
	this->_energypoints = rhs._energypoints;
	this->_hitpoints = rhs._hitpoints; */
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " was destroyed!" << std::endl;
}

/* • Name, which is passed as parameter to a constructor
• ClapTrap::name (parameter of the constructor + "_clap_name" suffix) 
• Hit points (FragTrap)
• Energy points (ScavTrap)
• Attack damage (FragTrap)
• attack() (Scavtrap) */