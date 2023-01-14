/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:14:10 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/14 21:16:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iomanip>

#include "Fixed.hpp"

class Point
{
	public:
		// Constructors
		Point(void);
		Point(const float, const float);
		Point(Point const &);

		// Deconstructors
		~Point(void);

		// Operator overloads
		Point	&operator=(Point const &);

		// Functions
		Fixed const	getX(void);
		Fixed const	getY(void);

	private:
		Fixed const	_x;
		Fixed const	_y;
};