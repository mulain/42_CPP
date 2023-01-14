/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:48 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/14 19:52:39 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#define SUBJECTMODE 1
// Subjectmode 1 -> ++ increments by the smallest possible unit
// Subjectmode 0 -> ++ increments by 1.0

#include <iostream>
#include <iomanip>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &);
		Fixed(const int);
		Fixed(const float);
		~Fixed(void);

		// Assignment operator
		Fixed	&operator=(const Fixed &);

		// Comparison operators
		bool	operator==(const Fixed &) const;
		bool	operator>(const Fixed &) const;
		bool	operator<(const Fixed &) const;
		bool	operator>=(const Fixed &) const;
		bool	operator<=(const Fixed &) const;
		bool	operator!=(const Fixed &) const;

		// Arithmetic operators
		Fixed	operator+(const Fixed &) const;
		Fixed	operator-(const Fixed &) const;
		Fixed	operator*(const Fixed &) const;
		Fixed	operator/(const Fixed &) const;

		// Prefix increment / decrement operators
		Fixed&	operator++(void);
		Fixed&	operator--(void);

		// Postfix increment / decrement operators
		Fixed	operator++(int);
		Fixed	operator--(int);

		// Conversions
		float	toFloat(void) const;
		int		toInt(void) const;

		// Get / set raw bits
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);

		// Min
		static Fixed	&min(Fixed &, Fixed &);
		static Fixed	const &min(Fixed const &, Fixed const &);

		// Max
		static Fixed	&max(Fixed &, Fixed &);
		static Fixed	const &max(Fixed const &, Fixed const &);

	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &, Fixed const &);

#endif