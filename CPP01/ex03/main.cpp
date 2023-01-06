/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:45:22 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/06 16:53:45 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string>
#include <iostream>

/*
Write a program that contains:
• A string variable initialized to "HI THIS IS BRAIN".
• stringPTR: A pointer to the string.
• stringREF: A reference to the string.
Your program has to print:
• The memory address of the string variable.
• The memory address held by stringPTR.
• The memory address held by stringREF.
And then:
• The value of the string variable.
• The value pointed to by stringPTR.
• The value pointed to by stringREF
*/

int	main(void)
{
	std::string		string;
	std::string		*stringPTR;

	stringPTR = &string;
	std::cout << ptr << std::endl;
	string = "HI THIS IS BRAIN";
	std::cout << "string content: " << string << std::endl;
	std::cout << "stringPTR: " << stringPTR << std::endl;


}