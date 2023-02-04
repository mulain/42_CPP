/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:41:46 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/04 11:04:59 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void):
	_size(10)
{
	std::cout << "Instantiating a Span object without parameters. Size (N) set to: 10." << std::endl;
}

Span::~Span(void)
{}

Span::Span(unsigned int N):
	_size(N)
{}

Span::Span(const Span& src)
{
	*this = src;
}

Span& Span::operator=(const Span& src)
{
	_size = src._size;
	_content.resize(src._content.size());
	std::copy(src._content.begin(), src._content.end(), _content.begin());
	return *this;
}

void Span::addNumber(int number)
{
	checkFull();
	_content.push_back(number);
}

unsigned int Span::shortestSpan(void)
{
	
}

unsigned int Span::longestSpan(void)
{
	
}

void Span::checkFull(void)
{
	if (_content.size() == _size)
		throw std::out_of_range("No space left, cannot add number.");
}

void Span::checkLogic(void)
{
	if (_content.size() < 2)
		throw std::logic_error("Less than 2 values present, cannot calculate a span.");
}