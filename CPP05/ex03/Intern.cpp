/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:50:53 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/29 13:06:00 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	return;
}

Intern::~Intern(void)
{
	return;
}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern& Intern::operator=(const Intern& src)
{
	(void)src;
	return *this;
}

/*
Didn't come up with a better way to define the list of possible return objects than actually allocating the 
entire list. Maybe some way to use an enum? Pretty sure this is possible (even without forbidden libraries).
*/
AForm* Intern::makeForm(std::string formtype, std::string target)
{
	std::string		compareList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm*			formList[4] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target), NULL};	
	int 			i = 0;
	
	while (i < 3 && formtype.compare(compareList[i]))
		i++;
	if (i == 3)
		std::cout << "Unknown form type, could not create form. Known types are: <shrubbery creation>, <robotomy request> and <presidential pardon>." << std::endl;
	for (int j = 0; formList[j]; j++)
		if (j != i)
			delete formList[j];
	return formList[i];
}
