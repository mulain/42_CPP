/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:23:09 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/10 21:58:20 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define E_ARGCOUNT	"Please enter exactly one string to represent the starting level of Harl's complaining."
#define E_NOMATCH	"No matching error level found. Valid level selector strings are: <DEBUG>, <INFO>, <WARNING> and <ERROR>."

int	main(int argc, char **argv)
{
	Harl			harl;
	std::string		filter;
	std::string		filter_lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int				i;

	if (argc != 2)
	{
		std::cout << E_ARGCOUNT << std::endl;
		return (1);
	}
	filter = argv[1];
	for (i = 0; i < 4; i++)
	{
		if (filter_lvls[i] == filter)
			break;
	}
	switch (i)
	{
		case (0):
			harl.complain("DEBUG");
		case (1):
			harl.complain("INFO");
		case (2):
			harl.complain("WARNING");
		case (3):
			harl.complain("ERROR");
			break;
		default:
			std::cout << E_NOMATCH << std::endl;


	}
}