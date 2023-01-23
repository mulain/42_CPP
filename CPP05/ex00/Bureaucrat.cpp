/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:24:09 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/23 20:50:01 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define HIGHGRADE	1
#define LOWGRADE	150

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
	_name(src._name)
{
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	_grade = src._grade;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade == LOWGRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade == HIGHGRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

const std::string Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < HIGHGRADE)
		throw Bureaucrat::GradeTooHighException();
	if (grade > LOWGRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& const bur)
{
	std::cout << "Bureaucrat " << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return o;
}
