/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:06:01 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/22 11:49:06 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &);
		virtual ~WrongAnimal(void);
		
		WrongAnimal & operator=(WrongAnimal const &);

		virtual void makeSound(void) const;
		std::string getType(void) const;

	protected:
		std::string _type;
};

#endif
