/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:18:43 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/15 11:14:26 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void):
	_x(0),
	_y(0)
{
	return;
}

Point::Point(std::string name, const float x, const float y):
	_name(name),
	_x(x),
	_y(y)
{
	return;
}

Point::Point(Point const &src):
	_name(src._name + "_copy"),
	_x(src._x),
	_y(src._y)
{
	return;
}

Point::~Point(void)
{
	return;
}

Point	&Point::operator=(Point const &)
{
	return (*this);
}

std::string	Point::getName(void) const
{
	return (_name);
}

Fixed const	Point::getX(void) const
{
	return (_x);
}

Fixed const Point::getY(void) const
{
	return (_y);
}

std::ostream &operator<<(std::ostream &oStream, Point const &pointObj)
{
	std::cout << pointObj.getName() << "(" << pointObj.getX() << "," << pointObj.getY() << ")";
	return (oStream);
}