/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:24:09 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/23 16:33:24 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void):
	_name("Unnamed Burryboi"),
	_grade(150)
{
	return;
}

Bureaucrat::~Bureaucrat(void)
{
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name),
	_grade(grade)
{
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src):
	_name(src._name),
	_grade(src._grade)
{
	return;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	_grade = src._grade;
}