/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:43 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 19:54:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(std::string);
        DiamondTrap(DiamondTrap const &);
        ~DiamondTrap(void);

        DiamondTrap &   operator=(DiamondTrap const &);

        using ScavTrap::attack;
        using ScavTrap::takeDamage;
        using ScavTrap::beRepaired;
        void    whoAmI(void); //This member function will display both its name and its ClapTrap name.

    private:
        std::string     _name;
        using FragTrap::_hitpoints;
        using ScavTrap::_energypoints;
        using FragTrap::_attackdmg;
};

#endif