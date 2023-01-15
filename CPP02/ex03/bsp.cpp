/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:07:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/15 13:26:51 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// Function to check if point p is left or right of a line defined by l1 and l2
// "Left" refers to the side of the line that would be left in movement direction l1 to l2.
bool	isLeft(Point l1, Point l2, Point p)
{
    return ((l2.getX().toFloat() - l1.getX().toFloat()) * (p.getY().toFloat() - l1.getY().toFloat()) - (l2.getY().toFloat() - l1.getY().toFloat()) * (p.getX().toFloat() - l1.getX().toFloat())) > 0;
}

bool	bsp(Point const a, Point const b, Point const c, Point const p)
{
	bool b1 = isLeft(a, b, p);
    bool b2 = isLeft(b, c, p);
    bool b3 = isLeft(c, a, p);
    return ((b1 == b2) && (b2 == b3));
}