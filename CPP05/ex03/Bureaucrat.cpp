/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:24:09 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/28 15:00:55 by wmardin          ###   ########.fr       */
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
	_name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src):
	_name(src._name)
{
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
	setGrade(src._grade);
	return *this;
}

void Bureaucrat::decrementGrade(void)
{
	setGrade(_grade + 1);
}

void Bureaucrat::incrementGrade(void)
{
	setGrade(_grade - 1);
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

void Bureaucrat::signForm(AForm& form)
{
	std::cout << "Bureaucrat " << _name;
	try
	{
		form.beSigned(*this);
		std::cout << " signed form " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << " failed to sign form " << form.getName() << ": ";
		std::cout << e.what() << std::endl;
		return;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bur)
{
	std::cout << "Bureaucrat " << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
	return o;
}
