/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/19 08:48:34 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
You must create a program with these constraints:
• The program name is RPN.
• Your program must take an inverted Polish mathematical expression as an argu- ment.
• The numbers used in this operation and passed as arguments will always be less than 10. The calculation itself but also the result do not take into account this rule.
• Your program must process this expression and output the correct result on the standard output.
• If an error occurs during the execution of the program an error message should be displayed on the standard output.
• Your program must be able to handle operations with these tokens: "+ - / *".

For example, the infix expression (3 × 4) + (5 × 6) becomes 3 4 × 5 6 × + in reverse Polish notation.
3456
xx+

*/

#include <iostream>
#include <stack>

std::string syntaxCheck(int argc, char **argv)
{
	std::string input;
	
	if (argc < 2)
	{
		std::cout << "Please provide an argument." << std::endl;
		exit(1);
	}
	input = argv[1];
	if (input.empty())
	{
		std::cout << "Nothing to do..." << std::endl;
		exit(0);
	}
	if (input.find_first_not_of("0123456789+-/* ") != std::string::npos)
	{
		std::cout << "Illegal character detected." << std::endl;
		exit(1);
	}
	return input;
}

void performOperation(std::stack<int> *numbers, char operand)
{
	if (numbers->size() < 2)
	{
		std::cout << "Found less than 2 numbers to perform on for operand: " << operand << std::endl;
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
