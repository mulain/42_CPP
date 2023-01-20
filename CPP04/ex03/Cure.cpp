/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:40:08 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/20 09:41:26 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	_type = "cure";
}

Cure::~Cure(void)
{
	return;
}

Cure::Cure(Cure const & src): AMateria()
{
	*this = src;
}

Cure &Cure::operator=(Cure const & src)
{
	
	_type = src._type;
	return *this;
}

AMateria *Cure::clone(void) const
{
	AMateria * clone;

	clone = new Cure(*this);
	return clone;
}

void Cure::use(ICharacter & target) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
