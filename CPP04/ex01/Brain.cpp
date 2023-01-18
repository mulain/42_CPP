/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:37:42 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 12:11:34 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#define CLASSNAME "Brain"

Brain::Brain(void)
{
	std::cout << CLASSNAME << " standard constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = i;
}

Brain::~Brain(void)
{
	std::cout << CLASSNAME << " standard destructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	std::cout << CLASSNAME << " copy constructor called" << std::endl;
	*this = src;
}

Brain & Brain::operator=(Brain const & rhs)
{
	std::cout << CLASSNAME << " copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	return *this;
}

void Brain::setIdea(int i, std::string idea)
{
	if (!validIndex(i))
		std::cout << "Invalid index." << std::endl;
	else
		_ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	if (!validIndex(i))
	{
		std::cout << "Invalid index." << std::endl;
		return NULL;
	}
	else
		return _ideas[i];
}

bool Brain::validIndex(int i) const
{
	return (i >= 0 && i < 100);
}