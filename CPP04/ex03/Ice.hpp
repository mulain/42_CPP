/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:40:59 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/20 09:33:42 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		Ice(Ice const &);

		Ice & operator=(Ice const &);

		AMateria *clone(void) const;
		virtual void use(ICharacter &target) const;

	protected:
};

#endif