/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:37:18 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/21 20:45:06 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include  "AMateria.hpp"

class Character: public ICharacter
{
	public:
		Character(void);
		~Character(void);
		Character(std::string const);
		Character(Character const &);

		Character & operator=(Character const &);

		std::string const & getName(void) const;
		AMateria * getMatAddr(int) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria * _inventory[4];
};

#endif
