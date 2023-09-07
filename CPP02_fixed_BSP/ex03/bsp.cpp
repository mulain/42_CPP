/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wolf <wolf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:07:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/17 10:49:31 by wolf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// Function to check if point p is left or right of a line defined by l1 and l2
// "Left" refers to the side of the line that would be left in movement direction l1 to l2.
bool	isLeft(Point const l1, Point const l2, Point const p)
{
	float i = (l2.getX().toFloat() - l1.getX().toFloat()) * (p.getY().toFloat() - l1.getY().toFloat());
	float j = (l2.getY().toFloat() - l1.getY().toFloat()) * (p.getX().toFloat() - l1.getX().toFloat());
	return (i - j > 0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	bool b1 = isLeft(a, b, p);
    bool b2 = isLeft(b, c, p);
    bool b3 = isLeft(c, a, p);
    return ((b1 == b2) && (b2 == b3));
}