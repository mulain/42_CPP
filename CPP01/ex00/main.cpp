/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:38:44 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/05 22:21:39 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*newZomb;

	newZomb = newZombie("Bert");
	newZomb->announce();
	randomChump("Amelia");
	delete newZomb;
}