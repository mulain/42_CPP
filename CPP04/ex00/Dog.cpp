/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:34:49 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 20:39:53 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define CLASSNAME	"Dog"

Dog::Dog(void)
{
	std::cout << CLASSNAME << " standard constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << CLASSNAME << " standard destructor called" << std::endl;
}

Dog::Dog(Dog const &src): Animal()
{
	*this = src;
	std::cout << CLASSNAME << " copy constructor called" << std::endl;
}

Dog Dog::&operator=(Dog const & src)
{
	_type
}

