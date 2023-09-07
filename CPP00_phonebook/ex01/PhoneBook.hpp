/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:27:06 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/03 18:29:08 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <ios>
#include <stdlib.h>
#include "Contact.hpp"

#define E_BLANK			"phonebook: field may not be blank"
#define E_INVAL			"phonebook: input must be from 0 to "
#define E_INDEXEMPTY	"phonebook: selected index has no saved contact"
#define E_BOOKEMPTY		"phonebook: no saved contacts"
#define E_BLANK			"phonebook: field may not be blank"
#define BOOKSIZE		8

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		bool			empty(void);
		void			add_contact(void);
		void			display_toc(void);
		int				select_contact(void);
		void			display_contact(int);
		std::string		display_version(std::string);

	private:
		int			_nbContacts;
		int			_index;
		Contact		_contacts[BOOKSIZE];
};

#endif