/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:33:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/28 14:07:56 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat bur;
	ShrubberyCreationForm shrubbs;
	
	try
	{
		shrubbs.beExecuted(bur);
	}
	catch(std::exception& e)
	{
		std::cout << bur.getName() << " failed to execute " << shrubbs.getName() << ": ";
		std::cout << e.what() << std::endl;
	}
	try
	{
		shrubbs.beSigned(bur);
	}
	catch(std::exception& e)
	{
		std::cout << bur.getName() << " failed to sign " << shrubbs.getName() << ": ";
		std::cout << e.what() << std::endl;
	}

	Bureaucrat big("bigboiii", 1);
	try
	{
		shrubbs.beExecuted(big);
	}
	catch(std::exception& e)
	{
		std::cout << big.getName() << " failed to execute " << shrubbs.getName() << ": ";
		std::cout << e.what() << std::endl;
	}
	try
	{
		shrubbs.beSigned(big);
	}
	catch(std::exception& e)
	{
		std::cout << big.getName() << " failed to sign " << shrubbs.getName() << ": ";
		std::cout << e.what() << std::endl;
	}
	try
	{
		shrubbs.beExecuted(big);
	}
	catch(std::exception& e)
	{
		std::cout << big.getName() << " failed to execute " << shrubbs.getName() << ": ";
		std::cout << e.what() << std::endl;
	}

}