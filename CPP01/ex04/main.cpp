/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:05:13 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/10 15:50:55 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define E_ARGCOUNT		"Wrong number of arguments. Please provide <filename>, <string1>, <string2>"
#define E_INVALIDARG	"<string1> and <string2> may not be empty."
#define E_INFILE		"Infile error."
#define E_OUTFILE		"Outfile error. "

/*
Create a program that takes three parameters in the following order:
a filename and two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file <filename>.replace,
replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating.
All the member functions of the class std::string are allowed, except replace. Use them wisely!
Of course, handle unexpected inputs and errors.
You have to create and turn in your own tests to ensure your program works as expected

forbidden: std::string::replace
*/

int	main(int argc, char **argv)
{
	std::string		outfile_name;
	std::string		buffer;
	std::string		content;
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4)
	{
		std::cout << E_ARGCOUNT << std::endl;
		return (1);
	}
	if (!argv[2][0] || !argv[3][0]) //wrong. argv2.empty should just copy the file and argv3.empty should delete argv2 occurences
	{
		std::cout << E_INVALIDARG << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (!infile.is_open())
	{
		std::cout << E_INFILE << std::endl;
		return (1);
	}
	outfile_name = argv[1];
	outfile_name.append(".replace");
	outfile.open(outfile_name);
	if (!outfile.is_open())
	{
		std::cout << E_OUTFILE << std::endl;
		return (1);
	}
	while (std::getline(infile, buffer))
		content.append(buffer + '\n');
	content.pop_back();
	infile.close();


}