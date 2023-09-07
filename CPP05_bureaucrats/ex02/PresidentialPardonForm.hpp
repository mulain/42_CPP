/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:52:56 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/01 22:23:25 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENT_HPP
#define PRESIDENT_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(std::string);
		PresidentialPardonForm(const PresidentialPardonForm&);

		PresidentialPardonForm& operator=(const PresidentialPardonForm&);

		void	execute(const Bureaucrat&);
};

#endif
