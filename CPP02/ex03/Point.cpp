/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:18:43 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/14 20:46:54 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void):
	_x(0),
	_y(0)
{
	return;
}

Point::Point(const float x, const float y):
	_x(x),
	_y(y)
{
	return;
}

Point::Point(Point const &src):
	_x(src._x),
	_y(src._y)
{
	return;
}

Point	&Point::operator=(Point const &rhs)
{
	return (*this);
}

Fixed const	Point::getX(void)
{
	return (_x);
}

Fixed const Point::getY(void)
{
	return (_y);
}