/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:55:53 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 12:10:00 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define CLASSNAME	"Cat"

Cat::Cat(void)
{
	std::cout << CLASSNAME << " standard constructor called" << std::endl;
	_type = CLASSNAME;
	_brain = new Brain();
}

Cat::~Cat(void)
{
	std::cout << CLASSNAME << " standard destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(Cat const & src): Animal()
{
	std::cout << CLASSNAME << " copy constructor called" << std::endl;
	_brain = new Brain();
	*this = src;
}

Cat &Cat::operator=(Cat const & src)
{
	std::cout << CLASSNAME << " copy assignment operator called" << std::endl;
	_type = src._type;
	*_brain = *src._brain;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meauuuu!" << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
	_brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const
{
	return _brain->getIdea(i);
}
