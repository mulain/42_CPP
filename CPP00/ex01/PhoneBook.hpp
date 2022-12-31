/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:27:06 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/31 16:16:01 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <ios>
#include <stdlib.h>
#include "Contact.hpp"

#define E_BLANK		"phonebook: field may not be blank. "

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void			add_contact(void);
		void			search_contact(void);
		void			display_toc(void);
		void			display_contact(int);
		std::string		display_version(std::string);

	private:
		unsigned char	_index;
		Contact			_contacts[8];
};

#endif