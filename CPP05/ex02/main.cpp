/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:33:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/29 11:22:44 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::string partition(50, '-');

	std::cout << partition << std::endl;
	std::cout << "Scope 1: Shrubbery" << std::endl;
	std::cout << partition << std::endl;
	{
		Bureaucrat bur;
		ShrubberyCreationForm form("Shrubbery target");
		
		try
		{
			form.beExecuted(bur);
		}
		catch(std::exception& e)
		{
			std::cout << bur.getName() << " failed to execute " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			form.beSigned(bur);
		}
		catch(std::exception& e)
		{
			std::cout << bur.getName() << " failed to sign " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}

		Bureaucrat big("bigboiii", 1); // required grade to sign: 145, to execute: 137.
		try
		{
			form.beExecuted(big);
		}
		catch(std::exception& e)
		{
			std::cout << big.getName() << " failed to execute " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			form.beSigned(big);
		}
		catch(std::exception& e)
		{
			std::cout << big.getName() << " failed to sign " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			form.beExecuted(big);
		}
		catch(std::exception& e)
		{
			std::cout << big.getName() << " failed to execute " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << partition << std::endl;
	std::cout << "Scope 2: Robotomy" << std::endl;
	std::cout << partition << std::endl;
	{
		Bureaucrat bur;
		RobotomyRequestForm form("Robotomy target");
	
		try
		{
			form.beExecuted(bur);
		}
		catch(std::exception& e)
		{
			std::cout << bur.getName() << " failed to execute " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			form.beSigned(bur);
		}
		catch(std::exception& e)
		{
			std::cout << bur.getName() << " failed to sign " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}

		Bureaucrat big("bigboiii", 45); // required grade to sign: 72, to execute: 45.
		try
		{
			form.beExecuted(big);
		}
		catch(std::exception& e)
		{
			std::cout << big.getName() << " failed to execute " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			form.beSigned(big);
		}
		catch(std::exception& e)
		{
			std::cout << big.getName() << " failed to sign " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			form.beExecuted(big);
		}
		catch(std::exception& e)
		{
			std::cout << big.getName() << " failed to execute " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << partition << std::endl;
	std::cout << "Scope 3: Pardon" << std::endl;
	std::cout << partition << std::endl;
	{
		Bureaucrat bur;
		PresidentialPardonForm form("Pardoning target");
	
		try
		{
			form.beExecuted(bur);
		}
		catch(std::exception& e)
		{
			std::cout << bur.getName() << " failed to execute " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			form.beSigned(bur);
		}
		catch(std::exception& e)
		{
			std::cout << bur.getName() << " failed to sign " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}

		Bureaucrat big("bigboiii", 5); // required grade to sign: 25, to execute: 5.
		try
		{
			form.beExecuted(big);
		}
		catch(std::exception& e)
		{
			std::cout << big.getName() << " failed to execute " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			form.beSigned(big);
		}
		catch(std::exception& e)
		{
			std::cout << big.getName() << " failed to sign " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
		try
		{
			form.beExecuted(big);
		}
		catch(std::exception& e)
		{
			std::cout << big.getName() << " failed to execute " << form.getName() << ": ";
			std::cout << e.what() << std::endl;
		}
	}
}
