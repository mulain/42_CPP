/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:33:13 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/07 22:41:32 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_H
#define HumanA_H

#include <iostream>

class HumanA
{
	public:
		HumanA(void);
		~HumanA(void);

		void	HumanA::attack(void);

	private:
		std::string		_weapon;
		std::string		_name;
};

#endif