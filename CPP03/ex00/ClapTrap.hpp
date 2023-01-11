/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:48 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/11 19:47:06 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string);
		~ClapTrap(void);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string		_name;
		int				_hitpoints;
		int				_energypoints;
		int				_attackdmg;


};

#endif

Turn-in directory : ex00/
Files to turn in : Makefile, main.cpp, ClapTrap.{h, hpp}, ClapTrap.cpp
Forbidden functions : None
First, you have to implement a class! How original!
It will be called ClapTrap and will have the following private attributes initialized
to the values specified in brackets:
• Name, which is passed as parameter to a constructor
• Hit points (10), represent the health of the ClapTrap
• Energy points (10)
• Attack damage (0)
Add the following public member functions so the ClapTrap looks more realistic:
• void attack(const std::string& target);
• void takeDamage(unsigned int amount);
• void beRepaired(unsigned int amount);
When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.
In all of these member functions, you have to print a message to describe what happens. For example, the attack() function may display something like (of course, without
the angle brackets):
ClapTrap <name> attacks <target>, causing <damage> points of damage!
The constructors and destructor must also display a message, so your peer-evaluators
can easily see they have been called.
Implement and turn in your own tests to ensure your code works as expected