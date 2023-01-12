/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:05:13 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/12 15:11:14 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <filesystem>

#define E_ARGCOUNT		"Wrong number of arguments. Please provide <filename>, <string1>, <string2>"
#define E_INVALIDARG	"<string1> (search string) may not be empty."
#define E_INFILE		"Infile error."
#define E_OUTFILE		"Outfile error."

void	open_iofiles(char **argv, std::ifstream &infile, std::ofstream &outfile)
{
	std::string		outfile_name;

	infile.open(argv[1]);
	if (!infile.is_open())
	{
		std::cout << E_INFILE << std::endl;
		exit(1);
	}
	outfile_name = argv[1];
	outfile_name.append(".replace");
	outfile.open(outfile_name.c_str());
	if (!outfile.is_open())
	{
		std::cout << E_OUTFILE << std::endl;
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	std::stringstream	buffer;
	std::string			content;
	std::string			string1;
	std::ifstream		infile;
	std::ofstream		outfile;
	size_t				index;

	if (argc != 4)
	{
		std::cout << E_ARGCOUNT << std::endl;
		return (1);
	}
	open_iofiles(argv, infile, outfile);
	// If string1 is empty or string1 = string2 -> just copy input file to output file
	string1 = argv[2];
	if (string1.empty() || string1 == argv[3])
	{
		outfile << infile.rdbuf();
		infile.close();
		return (0);
	}
	// Copy input file contents to stringstream object
	buffer << infile.rdbuf();
	infile.close();
	// Couldn't figure out how to modify the string in the stringstream object;
	// even using the member function <str>. So copied it to string object...
	content = buffer.str();
	index = content.find(string1);
	while (index != std::string::npos)
	{
		content.erase(index, string1.length());
		content.insert(index, argv[3]);
		index = content.find(string1);
	}
	// Copy buffer string into output file
	outfile << content;
	outfile.close();
}