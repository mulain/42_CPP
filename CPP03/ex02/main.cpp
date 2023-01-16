/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:56:52 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 11:33:59 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	trap1("Fraggy");

	trap1.attack("Evil Fraggy");
	trap1.takeDamage(5);
	trap1.beRepaired(5);
	trap1.takeDamage(1000);
	trap1.takeDamage(10);
	trap1.status();
	trap1.attack("Evil Fraggy");

	FragTrap 	trap2(trap1);
	trap2.status();
	trap2.beRepaired(19);

	FragTrap	trap3("ScAvenger");
	trap3.guardGate();

	ScavTrap	unnamed;
}