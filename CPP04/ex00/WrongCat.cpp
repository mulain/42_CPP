/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:55:53 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 09:51:09 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#define CLASSNAME	"WrongCat"

WrongCat::WrongCat(void)
{
	_type = CLASSNAME;
	std::cout << CLASSNAME << " standard constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << CLASSNAME << " standard destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src): WrongAnimal()
{
	*this = src;
	std::cout << CLASSNAME << " copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const & src)
{
	_type = src._type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "!uuuuaeM" << std::endl;
}
