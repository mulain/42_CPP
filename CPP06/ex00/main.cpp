/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:00:23 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/31 13:21:44 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <cmath>

/* typedef struct t_conversion
{
	char	charly;
	int		intsy;
	float	floater;
	double	doubl;
} t_conv; */

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
	
	// float block
	std::cout << "float: " << static_cast<float>(value) << (!(fmod(value, 1)) ? ".0f" : "f") << std::endl;

	// double block
	std::cout << "double: " << static_cast<double>(value) << (!(fmod(value, 1)) ? ".0" : "") << std::endl;
}

/*
This function is not really needed, but the subject demands that the input type be 
identified and the string be cast to it. Only then is the conversion to the other types
allowed. It would be way faster using "checkFormat", but hey.
Actually: I'm not doing this. This is just too wyld.

void convert(std::string input, t_conv* conv)
{
	double	value;
	char*	alpha;

	if (input.size() == 1 && !isdigit(input[0]))
	{
		std::cout << "Type: char" << std::endl;
		char ackchualtype = static_cast<char>(input[0]);
		conv->charly = ackchualtype;
		conv->intsy = static_cast<int>(ackchualtype);
		conv->floater = static_cast<float>(ackchualtype);
		conv->doubl = static_cast<double>(ackchualtype);
		return;
	}
	value = strtod(input.c_str(), &alpha);
	if (!alpha[0] && input.find('.') == std::string::npos)
	{
		std::cout << "Type: int" << std::endl;
		int ackchualtype = static_cast<int>(value);
		conv->charly = static_cast<char>(ackchualtype);
		conv->intsy = ackchualtype;
		conv->floater = static_cast<float>(ackchualtype);
		conv->doubl = static_cast<double>(ackchualtype);
		return;
	}
	if (alpha[0] == 'f' && alpha[1] == 0)
	{
		std::cout << "Type: float" << std::endl;
		float ackchualtype = static_cast<float>(value);
		conv->charly = static_cast<char>(ackchualtype);
		conv->intsy = static_cast<int>(ackchualtype);
		conv->floater = ackchualtype;
		conv->doubl = static_cast<double>(ackchualtype);
		return;
	}
	if (!alpha[0])
	{
		std::cout << "Type: double" << std::endl;
		double ackchualtype = static_cast<double>(value);
		conv->charly = static_cast<char>(ackchualtype);
		conv->intsy = static_cast<int>(ackchualtype);
		conv->floater = static_cast<float>(ackchualtype);
		conv->doubl = ackchualtype;
		return;
	}
	std::cout << "Invalid format." << std::endl;
	exit (1);	
}
*/

int main (int argc, char** argv)
{
	std::string 	input;
	//t_conv			conv;
	
	argcountCheck(argc);
	input = argv[1];
	handlePseudo(input);
	printScalars(checkFormat(input));
}