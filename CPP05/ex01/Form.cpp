/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:58:32 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/25 15:08:15 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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
	return;
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