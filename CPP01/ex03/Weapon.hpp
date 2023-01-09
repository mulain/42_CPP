/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:17:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/09 17:45:28 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string);
		~Weapon(void);

		const std::string&	getType(void) const;
		void				setType(std::string);

	private:
		std::string	const	_type;
};

#endif