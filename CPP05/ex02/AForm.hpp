/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:36:01 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/27 18:56:13 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		~AForm(void);
		AForm(std::string, int, int, std::string);
		AForm(const AForm&);

		AForm&	operator=(const AForm&);

		void				checkGradeBounds(void);
		
		const std::string	getName(void) const;
		bool 				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		std::string			getTarget(void) const;

		void				setIsSigned(bool);
		void				setTarget(std::string);
		
		void				beSigned(const Bureaucrat&);
		void				beExecuted(const Bureaucrat&);
		
		virtual	void		execute(const Bureaucrat&) = 0;
		
		class GradeTooHighException: public std::exception
		{
			const char* what(void) const throw();
		};

		class GradeTooLowException: public std::exception
		{
			const char* what(void) const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
		std::string			_target;
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif
