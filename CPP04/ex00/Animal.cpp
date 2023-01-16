/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:18:41 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 20:30:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal standard constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;

}

Animal::~Animal(void)
{
	std::cout << "Animal standard destructor called" << std::endl;
}

Animal Animal::operator=(Animal const & rhs)
{
	_type = rhs._type;
}