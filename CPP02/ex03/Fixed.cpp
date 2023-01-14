/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/14 19:51:25 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(void):
	_fixedPoint(0)
{
	return;
}

Fixed::Fixed(Fixed const &source)
{
	*this = source;
}

Fixed::Fixed(const int num):
	_fixedPoint(num << _fractionalBits)
{
	return;
}

Fixed::Fixed(const float num):
	_fixedPoint(roundf(num * (1 << _fractionalBits)))
{
	return;
}

// Destructor
Fixed::~Fixed(void)
{
	return;
}

// Getter: get uninterpreted value (raw bits)
int	Fixed::getRawBits(void) const
{
	return (_fixedPoint);
}

// Setter: set uninterpreted bits (raw bits)
void	Fixed::setRawBits(int const raw)
{
	_fixedPoint = raw;
}

// Getter: interpret raw bits as float.
float	Fixed::toFloat(void) const
{
	return ((float)_fixedPoint / (1 << _fractionalBits));
}

// Getter: interpret raw bits as integer.
int		Fixed::toInt(void) const
{
	return (_fixedPoint >> _fractionalBits);
}

// << operator overload
std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}

// = operator overload
Fixed	&Fixed::operator=(const Fixed &rhs)
{
	_fixedPoint = rhs.getRawBits();
	return(*this);
}

// Comparison operators

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

// Arithmetic operators

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

// Incrementation operators

// prefix
Fixed &Fixed::operator++(void)
{
	if (SUBJECTMODE)
		this->_fixedPoint++;
	else
		this->_fixedPoint += 1 << _fractionalBits;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	if (SUBJECTMODE)
		this->_fixedPoint--;
	else
		this->_fixedPoint -= 1 << _fractionalBits;
	return (*this);
}

// postfix
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	if (SUBJECTMODE)
		this->_fixedPoint++;
	else
		this->_fixedPoint += 1 << _fractionalBits;
	return temp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	if (SUBJECTMODE)
		this->_fixedPoint--;
	else
		this->_fixedPoint -= 1 << _fractionalBits;
	return temp;
}

// Min
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed	const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

// Max
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed	const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}