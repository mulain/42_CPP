/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/19 10:18:22 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

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


std::string syntaxCheck(int argc, char **argv)
{
	std::string input;
	
	if (argc < 2)
	{
		std::cout << "Please provide a list of positive ints to sort." << std::endl;
		exit(1);
	}
	input = argv[1];
	if (input.empty())
	{
		std::cout << "Nothing to do..." << std::endl;
		exit(0);
	}
	if (input.find_first_not_of("0123456789 ") != std::string::npos)
	{
		std::cout << "Illegal character detected." << std::endl;
		exit(1);
	}
	return input;
}

int main (int argc, char** argv)
{
	std::string input = syntaxCheck(argc, argv);
	std::stack<int> numbers;

	for (int i = 0; input[i]; i++)
	{
		if (input[i] == ' ')
			continue;
		else if (isdigit(input[i]))
			numbers.push(input[i] - 48);
		else
			performOperation(&numbers, input[i]);
	}
	if (numbers.size() > 1)
		std::cout << "Expected operand but found end of input." << std::endl;
	return std::cout << numbers.top() << std::endl, 0;
}
