/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:43 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 17:57:52 by wmardin          ###   ########.fr       */
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
        void    whoAmI(void);

    private:
        std::string     _name;
};

#endif