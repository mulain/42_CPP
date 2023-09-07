/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:39:55 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/05 22:41:07 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string);
		Zombie(void);
		~Zombie(void);

		void	setName(std::string);
		void	announce(void);

	private:
		std::string		_name;

};

Zombie*	zombieHorde(int, std::string);

#endif