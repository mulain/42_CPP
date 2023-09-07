/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:16:54 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/10 14:19:44 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_H
#define HumanB_H

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string);
		~HumanB(void);

		void	attack(void);
		void	setWeapon(Weapon&);

	private:
		std::string		_name;
		Weapon			*_weapon;
};

#endif