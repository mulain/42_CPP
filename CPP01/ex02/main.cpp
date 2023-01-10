/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:45:22 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/09 13:40:30 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string		string;
	std::string		*stringPTR;
	std::string		&stringREF = string;

	string = "HI THIS IS BRAIN";
	stringPTR = &string;
	std::cout << "Memory address of the string variable:\t" << &string << std::endl;
	std::cout << "Memory address held by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:\t" << &stringREF << std::endl;

	std::cout << "Value of the string variable:\t\t" << string << std::endl;
	std::cout << "Value pointed to by stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\t\t" << stringREF << std::endl;
}