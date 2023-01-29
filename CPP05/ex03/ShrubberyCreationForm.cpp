/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:10:34 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/29 11:07:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm::AForm("Unnamed Shrubbery Creation Form", 145, 137, "unspecified")
	
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm::AForm("Unnamed Shrubbery Creation Form", 145, 137, target)
	
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
	AForm::AForm(src.getName(), src.getSignGrade(), src.getExecGrade(), src.getTarget())
{
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	setIsSigned(src.getIsSigned());
	setTarget(src.getTarget());
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& bur)
{
	std::ofstream outfile((getTarget() + "_shrubbery").c_str());
	if (!outfile.is_open())
	{
		std::cout << "Shrubbery Creation Form: outfile error" << std::endl;
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		outfile << "        *" << std::endl\
				<< "       / \\" << std::endl\
				<< "      /  *\\" << std::endl\
				<< "     /     \\" << std::endl\
				<< "    /  *    \\" << std::endl\
				<< "   *    *  * *" << std::endl\
				<< "  / \\    *  / \\" << std::endl\
				<< " *   *     *   *" << std::endl\
				<< "      |   |" << std::endl\
				<< "      |   |" << std::endl << std::endl;
	}
	outfile.close();
	std::cout << getName() << " was executed by " << bur.getName() << "." << std::endl;
}
