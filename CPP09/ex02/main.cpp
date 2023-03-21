/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/21 11:17:43 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

$> ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::[..] : 0.00031 us
Time to process a range of 5 elements with std::[..] : 0.00014 us
$> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
Before: 141 79 526 321 [...]
After: 79 141 321 526 [...]
Time to process a range of 3000 elements with std::[..] : 62.14389 us
Time to process a range of 3000 elements with std::[..] : 69.27212 us
$> ./PmergeMe "-1" "2"
Error
$> # For OSX USER:
$> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`
[...]
$>

*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

typedef std::vector<int>::const_iterator vec_it;

void myExit(std::string msg, int exitcode)
{
	if (!msg.empty())
		std::cout << msg << std::endl;
	exit(exitcode);
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
	printVector("After", vec);
}
