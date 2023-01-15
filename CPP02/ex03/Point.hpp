/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:14:10 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/15 10:43:12 by wmardin          ###   ########.fr       */
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
		Point(std::string, const float, const float);
		Point(Point const &);

		// Deconstructors
		~Point(void);

		// Operator overloads
		Point	&operator=(Point const &);

		// Getters
		std::string	getName(void) const;
		Fixed const	getX(void) const;
		Fixed const	getY(void) const;

	private:
		std::string		_name;
		Fixed const		_x;
		Fixed const		_y;
};

std::ostream	&operator<<(std::ostream &, Point const &);