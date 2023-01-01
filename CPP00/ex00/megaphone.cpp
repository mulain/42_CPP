/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:40:57 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/01 18:17:30 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
 	{
 		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)toupper(argv[i][j]);
		/* if (argv[i + 1])
			std::cout << " "; */
	}
	std::cout << std::endl;
}

/*
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		std::string					str = argv[i];
		std::string::iterator		it = str.begin();
		std::string::iterator		it_e = str.end();
		for (; it != it_e; it++)
			std::cout << (char)toupper(*it);
	}
	std::cout << std::endl;
}
*/