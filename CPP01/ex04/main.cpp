/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:05:13 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/10 14:40:06 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#define E_ARGCOUNT	"Wrong number of arguments. Please provide <filename>, <string1>, <string2>"

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
	std::string		filename;
	std::string		outfile;

	//if (argc != 4 || !argv[2][0] || !argv[3][0]) Why this needed?
	if (argc != 4)
	{
		std::cout << E_ARGCOUNT << std::endl;
		return (1);
	}
	filename = argv[1];
	outfile = argv[1];
	outfile.append(".replace");
	//if (filename.)
}