/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:25:23 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/05 23:02:09 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define E_MSG	"Please enter exactly one int to determine the size of the horde!"

int	main (int argc, char **argv)
{
	std::string		input;

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
}