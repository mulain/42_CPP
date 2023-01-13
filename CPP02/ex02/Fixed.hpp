/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:48 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/13 16:00:40 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

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

		Fixed	&operator=(const Fixed &);

		//Comparison operators
		bool	operator==(const Fixed &) const;
		bool	operator>(const Fixed &) const;
		bool	operator<(const Fixed &) const;
		bool	operator>=(const Fixed &) const;
		bool	operator<=(const Fixed &) const;
		bool	operator!=(const Fixed &) const;

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void 	setRawBits(int const raw);

	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &, Fixed const &);

//Comparison operators
//>, <, >=, <=, == and !=

//Arithmetic operators
//+, -, *, and /.
//pre and post increment (n=4), take smallest representable into account

#endif