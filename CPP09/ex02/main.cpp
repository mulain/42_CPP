/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/21 09:17:30 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

/*
• Your program must be able to use a positive integer sequence as argument.
• Your program must use a merge-insert sort algorithm to sort the positive integer sequence.
• If an error occurs during program execution, an error message should be displayed on the standard output.
You must use at least two different containers in your code to
validate this exercise.  Your program must be able to handle at
least 3000 different integers.

Here are some additional guidelines on the information you should display line by line on the standard output
• On the first line you must display an explicit text followed by the unsorted positive integer sequence.
• On the second line you must display an explicit text followed by the sorted positive integer sequence.
• On the third line you must display an explicit text indicating the time used by your algorithm by specifying
the first container used to sort the positive integer sequence.
• On the last line you must display an explicit text indicating the time used by your algorithm by specifying
the second container used to sort the positive integer sequence.

*/
typedef std::vector<int>::const_iterator vec_it;

void myExit(std::string msg, int exitcode)
{
	if (!msg.empty())
		std::cout << msg << std::endl;
	exit(exitcode);
}

bool isOnlyDigits(std::string input)
{
	return input.find_first_not_of("0123456789") == std::string::npos;
}

bool parsePosInt(const char* input, int* result)
{
	long	num;
	char*	endptr;

	if (!input || !input[0])
		return false;
	num = strtol(input, &endptr, 10);
	if (num < 0 || num > INT_MAX || *endptr != 0)
		return false;
	*result = num;
	return true;
}

std::vector<int> syntaxCheck(int argc, char **argv)
{	
	std::vector<int>	list;
	int					num;
	
	if (argc < 3)
		myExit("Please provide a list of >= 2 positive ints to sort.", 1);
	for (size_t i = 1; argv[i]; i++)
	{
		if (parsePosInt(argv[i], &num))
			list.push_back(num);
		else
			myExit("Invalid input detected." , 1);
	}
	return list;
}

void printVector(std::string title, std::vector<int> vec)
{
	std::cout << title << ":\t";
	for (vec_it it = vec.begin(); it != vec.end();)
		std::cout << *it << (++it != vec.end() ? " " : "\n");
	
	
}

int main (int argc, char** argv)
{
	std::vector<int> vec = syntaxCheck(argc, argv);

	printVector("Before", vec);
}
