/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:36:01 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/25 15:06:41 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
	public:
		Form(void);
		~Form(void);
		Form(std::string, int, int);
		Form(const Form&);

		Form&	operator=(const Form&);

		const std::string	getName(void) const;
		bool 				getIsSigned(void) const;
		const int			getSignGrade(void) const;
		const int			getExecGrade(void) const;

		class GradeTooHighException: std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: std::exception
		{
			public:
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
