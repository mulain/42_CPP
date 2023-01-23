/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:24:37 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/23 16:36:11 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(std::string, int);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator=(const Bureaucrat&);

		int getGrade(void) const;
		const std::string getName(void) const;
		void incrementGrade(void);
		void decrementGrade(void);

		class GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif
