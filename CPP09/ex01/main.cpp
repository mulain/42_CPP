/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/26 08:33:42 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <cstdlib>
#include <sstream>

void myExit(const char* msg, int exitcode)
{
	if (msg)
		std::cout << msg << std::endl;
	exit(exitcode);
}

std::string syntaxCheck(int argc, char **argv)
{
	if (argc < 2)
		myExit("Please provide an argument.", 1);
	std::string input = argv[1];
	for (size_t i = input.find(" "); i != std::string::npos; i = input.find(" "))
		input.erase(i, 1);
	if (input.empty())
		myExit("Nothing to do..." , 0);
	if (input.find_first_not_of("0123456789+-/*") != std::string::npos)
		myExit("Illegal character detected.", 1);
	return input;
}

void performOperation(std::stack<int> *numbers, char operand)
{
	if (numbers->size() < 2)
	{
		std::cout << "Found less than 2 numbers to perform on for operand: " << operand << std::endl;
		if (!numbers->empty())
			std::cout << "Current result is: " << numbers->top() << std::endl;
		exit(1);
	}
	int rhs = numbers->top();
	numbers->pop();
	if (operand == '+')
		numbers->top()+= rhs;
	else if (operand == '-')
		numbers->top() -= rhs;
	else if (operand == '*')
		numbers->top() *= rhs;
	else if (operand == '/')
		numbers->top() /= rhs;
}

int main (int argc, char** argv)
{
	std::string input = syntaxCheck(argc, argv);
	std::stack<int> numbers;

	for (int i = 0; input[i]; i++)
	{
		if (isdigit(input[i]))
			numbers.push(input[i] - 48);
		else
			performOperation(&numbers, input[i]);
	}
	if (numbers.size() > 1)
		return std::cout << "Expected operand but found end of input.\n", 1;
	std::cout << numbers.top() << std::endl;
	return 0;
}
