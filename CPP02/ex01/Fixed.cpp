/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/11 13:13:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _integer(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = copy;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "Function <getRawBits> called" << std::endl;
	return (this->_frac_bits);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "Function <setRawbits> called" << std::endl;
	this->_integer = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called." << std::endl;
}
