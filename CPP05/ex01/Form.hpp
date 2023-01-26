/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:36:01 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/26 21:31:15 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		~Form(void);
		Form(std::string, int, int);
		Form(const Form&);

		Form&	operator=(const Form&);

		void				checkGradeBounds(void);
		const std::string	getName(void) const;
		bool 				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		void				beSigned(const Bureaucrat&);

		class GradeTooHighException: public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			const char* what() const throw();
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif
