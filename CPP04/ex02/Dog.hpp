/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:33:06 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 11:16:58 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		~Dog(void);
		Dog(Dog const &);
		
		Dog & operator=(Dog const &);
		
		virtual void makeSound(void) const;
	
	private:
		Brain* _brain;
};

#endif