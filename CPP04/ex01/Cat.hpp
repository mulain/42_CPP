/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:33:06 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 11:57:25 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		~Cat(void);
		Cat(Cat const &);
		
		Cat & operator=(Cat const &);
		
		virtual void makeSound(void) const;
		void setIdea(int, std::string);
		std::string getIdea(int) const;
	
	private:
		Brain* _brain;
};

#endif