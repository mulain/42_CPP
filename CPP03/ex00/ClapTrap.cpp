/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:41:04 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/11 19:54:38 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap(std::string name): _name(name), _hitpoints(10), _energypoints(10), attackdmg(0)
{
	std::cout << "ClapTrap " << name << " created." << std::endl;
}

~ClapTrap(void)
{
	std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

ClapTrap::attack(const std::string &target)
{

}

ClapTrap::takeDamage(unsigned int amount)
{

}

ClapTrap::beRepaired(unsigned int amount)
{

}