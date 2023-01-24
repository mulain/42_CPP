/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:33:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/24 14:31:55 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat burbs("Burbs", 36);
	std::cout << "Created " << burbs << std::endl << std::endl;

	std::cout << "Try block: UP, grade 151:" << std::endl;
	try
	{
		Bureaucrat up("UP", 151);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Try block: OP with grade 0 now:" << std::endl;
	try
	{
		Bureaucrat op("OP", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << "Try block: Gosu, grade 1 and Boon, 150:" << std::endl << std::endl;
	try
	{
		Bureaucrat gosu("Gosu", 1);
		Bureaucrat boon("Boon", 150);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Non try block now:" << std::endl;
	Bureaucrat gosu("Gosu", 1);
	Bureaucrat boon("Boon", 150);
	std::cout << "Result:" << std::endl;
	std::cout << gosu << std::endl;
	std::cout << boon << std::endl << std::endl;

	std::cout << "Trying to increment Gosu:" << std::endl;
	try
	{
		gosu.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << gosu << std::endl << std::endl;

	std::cout << "Trying to decrement Boon:" << std::endl;
	try
	{
		boon.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << boon << std::endl << std::endl;

	std::cout << "Trying to increment Boon:" << std::endl;
	try
	{
		boon.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << boon << std::endl << std::endl;
	std::cout << "Trying to decrement Gosu:" << std::endl;
	try
	{
		gosu.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << gosu << std::endl << std::endl;
}
