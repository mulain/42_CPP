/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:49:04 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/15 10:39:53 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	float	x;
	float	y;

	std::cout << "Define triangle by supplying coordinates for points a, b and c:" << std::endl;

	std::cout << "Enter x-axis coordinate for point a: ";
	std::cin >> x;
	std::cout << "Enter y-axis coordinate for point a: ";
	std::cin >> y;
	Point	a("a", x, y);

	std::cout << "Enter x-axis coordinate for point b: ";
	std::cin >> x;
	std::cout << "Enter y-axis coordinate for point b: ";
	std::cin >> y;
	Point	b("b", x, y);

	std::cout << "Enter x-axis coordinate for point c: ";
	std::cin >> x;
	std::cout << "Enter y-axis coordinate for point c: ";
	std::cin >> y;
	Point	c("c", x, y);

	std::cout << a << b << c << std::endl;

}