/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:48 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/15 15:24:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string);
		ScavTrap(ScavTrap const &);
		~ScavTrap(void);

		ScavTrap	&operator=(const ScavTrap &);
};

#endif