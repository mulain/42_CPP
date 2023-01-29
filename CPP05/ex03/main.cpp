/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:33:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/29 12:54:19 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
		Intern	intern1;
		AForm*	form1;

		form1 = intern1.makeForm("shrubbery creation", "gardenfile");
		if (form1)
		{
			std::cout << *form1 << std::endl;
			delete form1;
		}
	}
	std::cout << std::endl;

	std::cout << partition << std::endl;
	std::cout << "Scope 2: Unknown form" << std::endl;
	std::cout << partition << std::endl;
	{
		Intern	intern1;
		AForm*	form1;

		form1 = intern1.makeForm("knudel initialization", "shmangtown");
		if (form1)
		{
			std::cout << *form1 << std::endl;
			delete form1;
		}
	}
	std::cout << std::endl;


	std::cout << partition << std::endl;
	std::cout << "Scope 3: Robotomy form" << std::endl;
	std::cout << partition << std::endl;
	{
		Intern	intern1;
		AForm*	form1;

		form1 = intern1.makeForm("robotomy request", "shmangtown");
		if (form1)
		{
			std::cout << *form1 << std::endl;
			delete form1;
		}
	}
	std::cout << std::endl;

	std::cout << partition << std::endl;
	std::cout << "Scope 4: Pardon form" << std::endl;
	std::cout << partition << std::endl;
	{
		Intern	intern1;
		AForm*	form1;

		form1 = intern1.makeForm("presidential pardon", "Douglas Adams");
		if (form1)
		{
			std::cout << *form1 << std::endl;
			delete form1;
		}
	}
	std::cout << std::endl;

}