/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:58:32 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/25 17:46:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#define HIGHGRADE	1
#define	LOWGRADE 	150

Form::Form(void):
	_name("Unnamed Form"),
	_signGrade(1),
	_execGrade(1),
	_isSigned(false)
{
	return;
}

Form::~Form(void)
{
	return;
}

Form::Form(std::string name, int signGrade, int execGrade):
	_name(name),
	_signGrade(signGrade),
	_execGrade(execGrade),
	_isSigned(false)
{
	if (_signGrade < HIGHGRADE || _execGrade < HIGHGRADE)
		throw Form::GradeTooHighException();
	if (_signGrade > LOWGRADE || _execGrade > LOWGRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& src):
	_name(src._name + "_copy"),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade)
{
	//Not really efficient to use the assignment
	//operator here, but this is the structure I
	//am currently following: Assign as much as possible
	//using "="; it's just that there are mostly const
	//vars here so it's not very elegant.
	*this = src;
}

Form& Form::operator=(const Form& src)
{
	_isSigned = src._isSigned;
}

const std::string Form::getName(void) const
{
	return _name;
}

bool Form::getIsSigned(void) const
{
	return _isSigned;
}

const int Form::getSignGrade(void) const
{
	return _signGrade;
}

const int Form::getExecGrade(void) const
{
	return _execGrade;
}

const char* Form::GradeTooHighException::what() const
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const
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
				<< "." << std::endl;
}