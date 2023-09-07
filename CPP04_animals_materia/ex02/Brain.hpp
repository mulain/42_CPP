/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:21:53 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/22 11:53:20 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <cstdlib>

class Brain
{
	public:
		Brain(void);
		~Brain(void);
		Brain(Brain const &);

		Brain & operator=(Brain const &);

		void setIdea(int, std::string);
		std::string getIdea(int) const;

	protected:
		std::string _ideas[100];

		bool validIndex(int) const;
};

#endif
