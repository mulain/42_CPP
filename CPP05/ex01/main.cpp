/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:33:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/25 17:51:45 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Form tmp("C34", 98, 23);
	Form tmp2(tmp);
	std::cout << "Trying to create a form with a too low grade!" << std::endl;
	try
	{
		Form tmp3("OHNO", 151, 23);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "Trying to create a form with a too high grade!" << std::endl;
	try
	{
		Form tmp3("OHNO", 98, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat billy("Billy", 98);
	Bureaucrat bobby("Bobby", 99);
	std::cout << std::endl << tmp << std::endl;
	std::cout << tmp2 << std::endl;
	bobby.signForm(tmp);
	billy.signForm(tmp);
	tmp2 = tmp;
	std::cout << tmp2 << std::endl;

}