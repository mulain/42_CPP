/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:09:57 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/28 23:27:29 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm&);

		RobotomyRequestForm& operator=(const RobotomyRequestForm&);

		void	execute(const Bureaucrat&);
};

#endif