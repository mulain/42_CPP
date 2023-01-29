/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:58:32 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/29 12:51:08 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#define HIGHGRADE	1
#define	LOWGRADE 	150

/*
Not necessary to call "checkGradeBounds" in every constructor the way the variables
are being initialized now. But in a bigger project I would want to have this safeguard
because future changes might make this a potential input error point.
*/
Form::Form(void):
	_name("Unnamed Form"),
	_isSigned(false),
	_signGrade(1),
	_execGrade(1)
{
	checkGradeBounds();
}

Form::~Form(void)
{
	return;
}

Form::Form(std::string name, int signGrade, int execGrade):
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
	checkGradeBounds();
}

/*
Not really efficient to use the assignment operator here, but this is the structure I
am currently following: Assign as much as possible using "=".
Here there are mostly const vars, so there is only one var assignable per "=".
*/
Form::Form(const Form& src):
	_name(src._name + "_copy"),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade)
{
	*this = src;
	checkGradeBounds();
}

Form& Form::operator=(const Form& src)
{
	_isSigned = src._isSigned;
	return *this;
}

void Form::checkGradeBounds(void)
{
	if (_signGrade < HIGHGRADE || _execGrade < HIGHGRADE)
	{
		this->~Form();
		throw Form::GradeTooHighException();
	}
	if (_signGrade > LOWGRADE || _execGrade > LOWGRADE)
	{
		this->~Form();
		throw Form::GradeTooLowException();
	}
}

const std::string Form::getName(void) const
{
	return _name;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;
}

int Form::getSignGrade(void) const
{
	return _signGrade;
}

int Form::getExecGrade(void) const
{
	return _execGrade;
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return "Grade too low!";
}

void Form::beSigned(const Bureaucrat& bur)
{
	if (bur.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
	std::cout	<< (form.getIsSigned() ? "Signed form " : "Unsigned form ")\
				<< form.getName()\
				<< ", required grade to sign: " << form.getSignGrade()\
				<< ", required grade to execute: " << form.getExecGrade()\
				<< ".";
	return o;
}