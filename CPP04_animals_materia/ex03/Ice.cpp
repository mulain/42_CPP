/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:40:08 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/21 12:15:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	_type = "ice";
}

Ice::~Ice(void)
{
	return;
}

Ice::Ice(Ice const & src): AMateria()
{
	*this = src;
}

Ice &Ice::operator=(Ice const & src)
{
	
	_type = src._type;
	return *this;
}

AMateria *Ice::clone(void) const
{
	AMateria * clone;

	clone = new Ice(*this);
	return clone;
}

void Ice::use(ICharacter & target) //const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
