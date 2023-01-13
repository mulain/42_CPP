/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/13 10:30:01 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed(void):
	_fixedPoint(0)
{
	std::cout << "Default constructor called." << std::endl;
}

// Copy constructor
Fixed::Fixed(Fixed const &source)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = source;
}

// Int constructor
Fixed::Fixed(const int num):
	_fixedPoint(num)
{
	std::cout << "Int constructor called." << std::endl;
}

// Float constructor
Fixed::Fixed(const float num):
	_fixedPoint(num)
{
	std::cout << "Float constructor called." << std::endl;
}

// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Default destructor called." << std::endl;
}

// = operator overload
Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called." << std::endl;
	_fixedPoint = other.getRawBits();
	return(*this);
}

// Getters and Setters

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	_fixedPoint = raw;
}

// Calculators

float	Fixed::toFloat(void) const
{

}

int		Fixed::toInt(void) const
{
	return (_fixedPoint >> _fractionalBits);
}

// << operator overload (2nd "std::" isn't necessary, put it there to better understand the syntax)
std::ostream &std::operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}