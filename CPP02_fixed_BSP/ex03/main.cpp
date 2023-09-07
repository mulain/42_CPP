/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:49:04 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 18:19:20 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const p);

int	main(void)
{
	{
	Point const a("a", 1, 1);
	Point const b("b", 5, 1);
	Point const c("c", 3, 3);
	Point const p1("p1", 3, 1.5);		//inside
	Point const p2("p2", 2, 1);			//on hypotenuse (edge)
	Point const p3("p3", 4, 3);			//outside
	Point const p4("p4", 3, 0.99); 		//outside but with small fractional difference
	Point const p5("p5", 3, 3); 		//vertex c
	std::cout << "Triangle: " << a << b << c << std::endl;
	std::cout << "Point " << p1 << (bsp(a, b, c, p1) ? " is " : " is NOT ") << "inside the triangle" << std::endl;
	std::cout << "Point " << p2 << (bsp(a, b, c, p2) ? " is " : " is NOT ") << "inside the triangle" << std::endl;
	std::cout << "Point " << p3 << (bsp(a, b, c, p3) ? " is " : " is NOT ") << "inside the triangle" << std::endl;
	std::cout << "Point " << p4 << (bsp(a, b, c, p4) ? " is " : " is NOT ") << "inside the triangle" << std::endl;
	std::cout << "Point " << p5 << (bsp(a, b, c, p5) ? " is " : " is NOT ") << "inside the triangle" << std::endl;
	}
}