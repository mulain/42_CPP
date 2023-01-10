/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:33:13 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/10 13:29:28 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_H
#define HumanA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string, Weapon &);
		~HumanA(void);

		void	attack(void);
		void	setWeapon(Weapon);

	private:
		std::string		_name;
		Weapon			&_weapon;
};

#endif