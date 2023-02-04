/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:56:19 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/04 10:20:19 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A first easy exercise is the way to start off on the right foot.
Write a function template easyfind that accepts a type T. It takes two parameters.
The first one has type T and the second one is an integer.
Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.
If no occurrence is found, you can either throw an exception or return an error value
of your choice. If you need some inspiration, analyze how standard containers behave.
Of course, implement and turn in your own tests to ensure everything works as expected.
You don’t have to handle associative containers.
6
*/

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator easyFind(T container, int i)
{
	typename T::iterator iter;

	iter = find(container.begin(), container.end(), i);
	if (iter == container.end())
		throw std::runtime_error("Value not found.");
	return iter;
}

#endif
