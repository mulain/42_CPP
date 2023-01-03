/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:25:42 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/03 13:52:10 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#define	FIRSTNAME	1
#define	NICKNAME	2
#define	LASTNAME	3
#define	PHONENUM	4
#define	DARKSECRET	5

#define E_BLANK			"phonebook: field may not be blank"
#define E_INVAL			"phonebook: input must be from 0 to "
#define E_INDEXEMPTY	"phonebook: selected index has no saved contact"
#define E_BOOKEMPTY		"phonebook: no saved contacts"
#define BOOKSIZE		8

#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void	add_contact(std::string);

	private:
		int				_nbContacts;
		int				_index;
		std::string		_firstname;
		std::string		_lastname;
		std::string		_nickname;
		std::string		_phonenumber;
		std::string		_darkestsecret;

		std::string	get_input(void);
		void		set_firstname(void);
		void		set_lastname(void);
		void		set_nickname(void);
		void		set_phonenumber(void);
		void		set_darkestsecret(void);
};

#endif