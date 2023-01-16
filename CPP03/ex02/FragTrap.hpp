/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:53:25 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 11:58:23 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string);
		FragTrap(FragTrap const &);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &);

		void	attack(const std::string &target);
		void	highFivesGuys(void);
};

#endif