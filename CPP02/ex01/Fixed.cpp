/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/11 18:46:26 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): _fixed_point(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(Fixed const &source)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = source;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->_fixed_point = other._fixed_point;
	return(*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "Function <getRawBits> called" << std::endl;
	return (this->_frac_bits);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "Function <setRawbits> called" << std::endl;
	_fixed_point = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Default destructor called." << std::endl;
}
