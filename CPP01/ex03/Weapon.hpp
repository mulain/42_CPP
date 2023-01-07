/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:17:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/07 22:34:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	public:
		Weapon(void);
		~Weapon(void);

		const std::string&	getType(void);
		void				setType(std::string);

	private:
		std::string		_type;
};

#endif