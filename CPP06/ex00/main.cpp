/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:00:23 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/29 17:46:21 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

void argcountCheck(int argc)
{
	if (argc != 2)
	{
		std::cout << "Please enter exactly one argument!" << std::endl;
		exit (1);
	}
}

void formatCheck(std::string input)
{
	
}

void handlePseudo(std::string input)
{
	std::string compareList[8] = {"inf", "inff", "+inf", "+inff", "-inf", "-inff", "nan", "nanf"};
	int i = 0;
	
	while (i < 8 && input != compareList[i])
		i++;
	if (i < 8)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << ((i % 2) ? input : input + "f") << std::endl;
		std::cout << "double: " << ((i % 2) ? (input.substr(0, input.size() - 1)) : input) << std::endl;
		exit (0);
	}
}

int main (int argc, char** argv)
{
	argcountCheck(argc);
	std::string input(argv[1]);
	handlePseudo(input);
	formatCheck(input);
	std::cout << "Commencing rest" << std::endl;
}