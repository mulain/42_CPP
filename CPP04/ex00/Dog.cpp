/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:55:53 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/17 18:24:56 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define CLASSNAME	"Dog"

Dog::Dog(void)
{
	_type = CLASSNAME;
	std::cout << CLASSNAME << " standard constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << CLASSNAME << " standard destructor called" << std::endl;
}

Dog::Dog(Dog const & src): Animal()
{
	*this = src;
	std::cout << CLASSNAME << " copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const & src)
{
	_type = src._type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Wooof!" << std::endl;
}
