/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:36:01 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/24 14:40:28 by wmardin          ###   ########.fr       */
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

		Form& operator=(const Form&);


	private:
		const std::string _name;
		bool _isSigned;
		const int _reqSignGrade;
		const int _reqExecGrade;


};

#endif

/*
Then, let’s make a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it’s not). •
A constant grade required to sign it.
• And a constant grade required to execute it.
All these attributes are private, not protected.
The grades of the Form follow the same rules that apply to the Bureaucrat.
Thus, the following exceptions will be thrown if a form grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.
Same as before, write getters for all attributes and an overload of the insertion («)
 operator that prints all the form’s informations.
*/