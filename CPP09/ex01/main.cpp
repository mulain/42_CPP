/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:32:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/03/19 02:13:18 by wmardin          ###   ########.fr       */
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
	/* for (size_t i = 0; i < input.length(); i++)
	{
		if (input[i] == ' ')
		{
			input.erase(i);
			i--;
		}
	} */
	if (input.find_first_not_of("0123456789+-/* ") != std::string::npos)
	{
		std::cout << "Illegal character detected: " << input.find_first_not_of("0123456789+-/*") << std::endl;
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
	int result = numbers->top();
	numbers->pop();
	if (operand == '+')
		result += numbers->top();
	else if (operand == '-')
		result -= numbers->top();
	else if (operand == '*')
		result *= numbers->top();
	else if (operand == '/')
		result /= numbers->top();
	numbers->pop();
	std::cout << result << std::endl;
	numbers->push(result);
}

int main (int argc, char** argv)
{
	std::string input = syntaxCheck(argc, argv);
	std::stack<int> numbers;
	std::stack<int> operands;

	for (int i = 0; input[i]; i++)
	{
		if (input[i] == ' ')
			continue;
		else if (isdigit(input[i]))
		{
			if (numbers.size() > 1)
				return std::cout << "Expected operand but found end of input." << std::endl, 1;
			numbers.push(input[i] - 48);
		}
		else
			performOperation(&numbers, input[i]);
	}
	if (numbers.size() > 1)
		std::cout << "Expected operand but found end of input." << std::endl;
	return std::cout << numbers.top() << std::endl, 0;
}
