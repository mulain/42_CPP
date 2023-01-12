/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:48 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/12 20:17:46 by wmardin          ###   ########.fr       */
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
		Fixed(const int); //converts to corresponding fixed point val. frac bits val is also 8
		Fixed(const float); //same
		~Fixed(void);

		Fixed	&operator=(const Fixed &);
		float	toFloat(void) const;
		int		toInt(void) const;

		int		getRawBits(void) const;
		void 	setRawBits(int const raw);

	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
};

#endif