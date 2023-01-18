/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:55:53 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 11:50:16 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define CLASSNAME	"Dog"

Dog::Dog(void)
{
	std::cout << CLASSNAME << " standard constructor called" << std::endl;
	_type = CLASSNAME;
	_brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << CLASSNAME << " standard destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(Dog const & src): Animal()
{
	std::cout << CLASSNAME << " copy constructor called" << std::endl;
	_brain = new Brain();
	*this = src;
}

Dog &Dog::operator=(Dog const & src)
{
	std::cout << CLASSNAME << " copy assignment operator called" << std::endl;
	_type = src._type;
	*_brain = *src._brain;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Wooof!" << std::endl;
}
