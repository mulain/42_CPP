/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:43:06 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/02 10:52:02 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T* array, int len, void function(T&))
{
	for (int i = 0; i < len; i++)
		function(array[i]);
}

template<typename T>
void print(T tem)
{
	std::cout << tem << std::endl;
}

template<typename T>
void increment(T *tem)
{
	*tem++;
}


#endif
