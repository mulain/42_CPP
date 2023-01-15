/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:56:52 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/15 14:07:33 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	trap1("Clappy");

	trap1.attack("Dark Clappy");
	trap1.takeDamage(5);
	trap1.beRepaired(5);
	trap1.takeDamage(10);
	trap1.status();

	ClapTrap	trap2(trap1);
	trap2.status();
}