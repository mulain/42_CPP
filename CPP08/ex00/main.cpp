/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:42:02 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/03 22:18:18 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>

#include "easyfind.hpp"

int main (void)
{
	std::vector<int>	v1(10);

	for (int i = 1; i < 11; i++)
		v1[i] = i;

	std::vector<int>::iterator iter;
	iter = easyFind(v1, 12);
	
	return 0;
}
