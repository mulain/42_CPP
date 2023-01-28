/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:33:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/28 23:24:32 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::string partition(50, '-');

	std::cout << partition << std::endl;
	std::cout << "Scope 1: Shrubbery" << std::endl;
	std::cout << partition << std::endl;
	
	{
		Bureaucrat bur;
		ShrubberyCreationForm form;
		
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

		Bureaucrat big("bigboiii", 1);
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

		std::cout << partition << std::endl;
		std::cout << "Scope 2: Robotomy" << std::endl;
		std::cout << partition << std::endl;
		{
			Bureaucrat bur;
			RobotomyRequestForm form;
		
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

			Bureaucrat big("bigboiii", 1);
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

}