/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:45:51 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/12 18:59:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	std::cout << std::setw(20) << std::setfill('-') << '-' ;
	std::cout << " Start scope 1 ";
	std::cout << std::setw(20) << '-' << std::endl;
	{
		Fixed	a;
		Fixed	b(a);
		Fixed	c;

		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout << std::setw(20) << std::setfill('-') << '-' ;
	std::cout << " Start scope 2 ";
	std::cout << std::setw(20) << '-' << std::endl;
	{
		Fixed	a;

		std::cout << "a: " << a.getRawBits() << std::endl;

		a.setRawBits(2);
		std::cout << "a: " << a.getRawBits() << std::endl;

		Fixed	b(a);
		std::cout << "b: " << b.getRawBits() << std::endl;

		a.setRawBits(0);
		std::cout << "a: " << a.getRawBits() << std::endl;
		std::cout << "b: " << b.getRawBits() << std::endl;

	}
	return (0);
}