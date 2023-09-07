/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:56:52 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 18:03:25 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	trap1("Diddy");

	trap1.attack("P. Diddy");
	trap1.takeDamage(5);
	trap1.beRepaired(5);
	trap1.highFivesGuys();
	trap1.guardGate();
	trap1.takeDamage(1000);
	trap1.takeDamage(10);
	trap1.status();
	trap1.attack("B.I.G.");
	trap1.whoAmI();
}