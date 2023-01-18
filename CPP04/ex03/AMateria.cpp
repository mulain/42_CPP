/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:31:19 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 21:40:06 by wmardin          ###   ########.fr       */
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