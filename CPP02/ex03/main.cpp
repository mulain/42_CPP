/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:49:04 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/14 21:22:01 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	float	x;
	float	y;

	std::cout << "Define triangle (a, b, c):" << std::endl;
	std::cout << "Enter x-axis coordinate for point a: ";
	std::cin >> x;
	std::cout << "Enter y-axis coordinate for point a: ";
	std::cin >> y;

	Point	a(x, y);

}