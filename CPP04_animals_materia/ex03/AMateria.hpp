/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:06:01 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/21 20:44:59 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

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

		// Member functions
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string _type;
};

#endif
