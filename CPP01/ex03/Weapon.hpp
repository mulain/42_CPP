/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:17:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/07 22:28:58 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Implement a Weapon class that has:
• A private attribute type, which is a string.
• A getType() member function that returns a const reference to type.
• A setType() member function that sets type using the new one passed as parameter.
*/

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