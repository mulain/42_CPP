/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:26 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 20:31:46 by wmardin          ###   ########.fr       */
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

		Animal &operator=(Animal const &);

		void makeSound(void);

	protected:
		std::string _type;
};


#endif