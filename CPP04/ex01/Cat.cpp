/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:55:53 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/17 18:24:40 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define CLASSNAME	"Cat"

Cat::Cat(void)
{
	_type = CLASSNAME;
	std::cout << CLASSNAME << " standard constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << CLASSNAME << " standard destructor called" << std::endl;
}

Cat::Cat(Cat const & src): Animal()
{
	*this = src;
	std::cout << CLASSNAME << " copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const & src)
{
	_type = src._type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meauuuu!" << std::endl;
}
