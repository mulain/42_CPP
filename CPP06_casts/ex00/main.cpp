/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:00:23 by wmardin           #+#    #+#             */
/*   Updated: 2023/09/12 13:51:12 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cmath>

void argcountCheck(int argc)
{
	if (argc != 2)
	{
		std::cout << "Please enter exactly one argument!" << std::endl;
		exit (1);
	}
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

double checkFormat(std::string input)
{
	double	value;
	char*	alpha;
	
	if (input.size() == 1 && !isdigit(input[0]))
		return static_cast<double>(input[0]);
	value = strtod(input.c_str(), &alpha);
	if (!alpha[0] || (alpha[0] == 'f' && alpha[1] == 0))
		return value;
	std::cout << "Invalid format." << std::endl;
	exit (1);	
}

void printScalars(double value)
{
	// char block
	if (value < 0 || value > 255)
		std::cout << "char: impossible" << std::endl;
	else if (value < 32 || value > 126)
		std::cout << "char: non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	
	// int block
	if ( value < -2147483648 || value > 2147483647)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	
	// float & double block
	// check for decimal modulo and for scientific notation cutoff to print empty decimal place as shown in subject
	bool printDecimalZero = false;
	if (!fmod(value, 1) && value < 1e6 && value > -1e6)
		printDecimalZero = true;
	std::cout << "float: " << static_cast<float>(value) << (printDecimalZero ? ".0f" : "f") << std::endl;
	std::cout << "double: " << static_cast<double>(value) << (printDecimalZero ? ".0" : "") << std::endl;
}

int main (int argc, char** argv)
{
	std::string 	input;
	
	argcountCheck(argc);
	input = argv[1];
	handlePseudo(input);
	printScalars(checkFormat(input));
	return 0;
}
