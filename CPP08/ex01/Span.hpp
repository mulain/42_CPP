/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:35:09 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/04 17:35:52 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span(void);
		~Span(void);
		Span(unsigned int);
		Span(const Span&);

		Span& operator=(const Span&);

		void addNumber(int);
		void addSpan(std::vector<int>::iterator, std::vector<int>::iterator);
		unsigned int shortestSpan();
		unsigned int longestSpan();
	
	private:
		void checkFull(void);
		void checkLogic(void);
		
		unsigned int		_size;
		std::vector<int>	_content;
};

#endif
