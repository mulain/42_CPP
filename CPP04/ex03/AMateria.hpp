/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:06:01 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 21:35:36 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class AMateria
{
	public:
		// Constructors / Destructors
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const &);
		virtual ~AMateria(void);
		
		// Operator overloads
		AMateria & operator=(AMateria const &);

		// Attributes
		std::string _type;

		// Member functions
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		//The use(ICharacter&) member function will display:
		//• Ice: "* shoots an ice bolt at <name> *"
		//• Cure: "* heals <name>’s wounds *"
	

	protected:

};

#endif