/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:05:13 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/12 13:58:29 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define E_ARGCOUNT		"Wrong number of arguments. Please provide <filename>, <string1>, <string2>"
#define E_INVALIDARG	"<string1> (search string) may not be empty."
#define E_INFILE		"Infile error."
#define E_OUTFILE		"Outfile error."

int	main(int argc, char **argv)
{
	std::string			outfile_name;
	std::stringstream	buffer;
	std::string			content;
	std::string			string1;
	std::ifstream		infile;
	std::ofstream		outfile;
	size_t				index;

	// Check input
	if (argc != 4)
	{
		std::cout << E_ARGCOUNT << std::endl;
		return (1);
	}
	// Manage input file
	infile.open(argv[1]);
	if (!infile.is_open())
	{
		std::cout << E_INFILE << std::endl;
		return (1);
	}
	// Manage output file
	outfile_name = argv[1];
	outfile_name.append(".replace");
	outfile.open(outfile_name.c_str());
	if (!outfile.is_open())
	{
		std::cout << E_OUTFILE << std::endl;
		return (1);
	}
	// Copy input file contents to buffer stringstream
	buffer << infile.rdbuf();
	// Couldn't figure out how to manipulate the stringstream object; even using the string function...
	content = buffer.str();
	infile.close();
	// Replace string1 with string2 if string1 is not empty and string1 is not same as string2
	string1 = argv[2];
	if (!string1.empty() && string1.compare(argv[3]) != 0)
	{
		index = buffer.str().find(string1);
		while (index != std::string::npos)
		{
			content.erase(index, string1.length());
			content.insert(index, argv[3]);
			index = content.find(string1);
			std::cout << "shamgfsdfs" << std::endl;
		}
	}
	// Copy buffer string into output file
	outfile << content;
	outfile.close();
}