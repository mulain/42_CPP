/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:27:02 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/02 08:33:14 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template <typename T>
void swap(T& a, T& b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T& min(T& a, T& b)
{
	return (a < b ? a : b);
}

template <typename T>
T& max(T& a, T& b)
{
	return (a > b ? a : b);
}

#endif
