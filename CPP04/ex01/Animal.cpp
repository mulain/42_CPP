/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:52:24 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 11:40:38 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define CLASSNAME	"Animal"

Animal::Animal(void):
	_type("Unspecified family")
{
	std::cout << CLASSNAME << " standard constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << CLASSNAME << " standard destructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	std::cout << CLASSNAME << " copy constructor called" << std::endl;
	*this = src;
}

Animal &Animal::operator=(Animal const & rhs)
{
	std::cout << CLASSNAME << " copy assignment operator called" << std::endl;
	_type = rhs._type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "Eerie sounds from the mists of time permeate the air." << std::endl;
}

std::string Animal::getType(void) const
{
	return _type;
}