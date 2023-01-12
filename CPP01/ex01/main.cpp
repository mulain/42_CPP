/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:25:23 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/12 08:31:35 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

#define E_MSG	"Please enter exactly one int to determine the size of the horde!"

int	main (int argc, char **argv)
{
	std::string		input;
	int				n;
	Zombie			*horde;

	if (argc != 2)
	{
		std::cout << E_MSG << std::endl;
		return (1);
	}
	input = argv[1];
	if (input.find_first_not_of("0123456789", 0) != input.npos)
	{
		std::cout << E_MSG << std::endl;
		return (1);
	}
	n = (int)strtol(input.c_str(), NULL, 10);
	horde = zombieHorde(n, "Hugo");
	for (int i = 0; i < n; i++)
		horde[i].announce();
	delete[] horde;
	Zombie test;
	Zombie test2("Josie");
	return (0);
}