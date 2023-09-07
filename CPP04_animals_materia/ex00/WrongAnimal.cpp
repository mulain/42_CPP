/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:52:24 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/22 11:49:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define CLASSNAME	"WrongAnimal"

WrongAnimal::WrongAnimal(void):
	_type("Wrong Unspecified family")
{
	std::cout << CLASSNAME << " standard constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << CLASSNAME << " standard destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	*this = src;
	std::cout << CLASSNAME << " copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const & rhs)
{
	_type = rhs._type;
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "The wrong eerie sounds from the mists of time permeate the air!" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return _type;
}
