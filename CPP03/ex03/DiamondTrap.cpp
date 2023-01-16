/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:38 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 18:07:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

Diamondtrap::Diamondtrap(void)
{
    _name = "Unnamed Diamondtrap";
    _hitpoints = this->FragTrap::_hitpoints;
	_energypoints = 100;
	_attackdmg = 30;
	std::cout << "Unnamed DiamondTrap created." << std::endl;
}

• Name, which is passed as parameter to a constructor
• ClapTrap::name (parameter of the constructor + "_clap_name" suffix) 
• Hit points (FragTrap)
• Energy points (ScavTrap)
• Attack damage (FragTrap)
• attack() (Scavtrap)