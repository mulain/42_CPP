/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:06:01 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 15:11:17 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(Animal const &);
		virtual ~Animal(void);
		
		Animal & operator=(Animal const &);

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;

	protected:
		std::string _type;
};

#endif