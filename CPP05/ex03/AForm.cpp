/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:58:32 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/29 12:50:48 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#define HIGHGRADE	1
#define	LOWGRADE 	150

/*
Not necessary to call "checkGradeBounds" in every constructor the way the variables
are being initialized now. But in a bigger project I would want to have this safeguard
because future changes might make this a potential input error point.
*/
AForm::AForm(void):
	_name("Unnamed Form"),
	_isSigned(false),
	_signGrade(1),
	_execGrade(1),
	_target("unspecified")
{
	checkGradeBounds();
}

AForm::~AForm(void)
{
	return;
}

AForm::AForm(std::string name, int signGrade, int execGrade, std::string target):
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_execGrade(execGrade),
	_target(target)
{
	checkGradeBounds();
}

/*
Not really efficient to use the assignment operator here, but this is the structure I
am currently following: Assign as much as possible using "=".
Here there are mostly const vars, so there is only one var assignable per "=".
Ackchually: added another in ex02, so it does make sense this way.
*/
AForm::AForm(const AForm& src):
	_name(src._name + "_copy"),
	_signGrade(src._signGrade),
	_execGrade(src._execGrade)
{
	*this = src;
	checkGradeBounds();
}

AForm& AForm::operator=(const AForm& src)
{
	_isSigned = src._isSigned;
	_target = src._target;
	return *this;
}

void AForm::checkGradeBounds(void)
{
	if (_signGrade < HIGHGRADE || _execGrade < HIGHGRADE)
	{
		this->~AForm();
		throw AForm::GradeTooHighException();
	}
	if (_signGrade > LOWGRADE || _execGrade > LOWGRADE)
	{
		this->~AForm();
		throw AForm::GradeTooLowException();
	}
}

const std::string AForm::getName(void) const
{
	return _name;
}

bool AForm::getIsSigned(void) const
{
	return _isSigned;
}

int AForm::getSignGrade(void) const
{
	return _signGrade;
}

int AForm::getExecGrade(void) const
{
	return _execGrade;
}

std::string AForm::getTarget(void) const
{
	return _target;
}

void AForm::setIsSigned(bool isSigned)
{
	_isSigned = isSigned;
}

void AForm::setTarget(std::string target)
{
	_target = target;
}

const char* AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade too low!";
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return "Form is not signed!";
}

void AForm::beSigned(const Bureaucrat& bur)
{
	if (bur.getGrade() > _signGrade)	
		throw AForm::GradeTooLowException();
	_isSigned = true;
	std::cout << getName() << " was signed by " << bur.getName() << "." << std::endl;
}

void AForm::beExecuted(const Bureaucrat& bur)
{
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	if (bur.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();
	execute(bur);
}

std::ostream& operator<<(std::ostream& o, const AForm& form)
{
	std::cout	<< (form.getIsSigned() ? "Signed form " : "Unsigned form ")\
				<< form.getName()\
				<<" with target: " << form.getTarget()\
				<< ", required grade to sign: " << form.getSignGrade()\
				<< ", required grade to execute: " << form.getExecGrade()\
				<< ".";
	return o;
}