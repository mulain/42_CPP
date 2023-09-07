/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:36:37 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/05 17:08:36 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
#define MUTANT_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(void) {}
		~MutantStack(void) {}
		MutantStack(const MutantStack& src)
		{
			*this = src;	
		}
		MutantStack& operator=(const MutantStack& src)
		{
			std::stack<T>::operator=(src);
			return *this;
		}
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void)
		{
			return std::stack<T>::c.begin();
		}
		
		iterator end(void)
		{
			return std::stack<T>::c.end();
		}
};

#endif
