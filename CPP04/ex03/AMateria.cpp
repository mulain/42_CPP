/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:31:19 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/21 12:29:55 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void):
	_type("base class")
{
	return;
}

AMateria::~AMateria(void)
{
	return;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria &AMateria::operator=(AMateria const & src)
{
	
	_type = src._type;
	return *this;
}

std::string const & AMateria::getType(void) const
{
	return _type;
}

// instead of supplying this to be overridden base function could also add "= 0" to declaration
// to make it pure virtual. But subject provided this part of the declaration without "= 0".
// Not sure about what is more useful to implement. Now it seems, "= 0" would be more pragmatic...
void AMateria::use(ICharacter& target)
{
	std::cout << "Virtual function base class used on " << target.getName() << "!" << std::endl; 
}
