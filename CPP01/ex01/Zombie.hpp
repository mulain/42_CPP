/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:39:55 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/05 22:08:05 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string);
		~Zombie(void);

		void	announce(void);

	private:
		std::string		_name;

};

Zombie	*newZombie(std::string);
void	randomChump(std::string);

#endif