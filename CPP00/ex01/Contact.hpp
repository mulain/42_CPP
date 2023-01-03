/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:25:42 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/03 18:19:36 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#define E_BLANK			"phonebook: field may not be blank"

#include <iostream>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void		add(void);
		void		display(void);
		bool		empty(void);
		std::string	get_firstname(void);
		std::string	get_lastname(void);
		std::string	get_nickname(void);

	private:
		std::string		_firstname;
		std::string		_lastname;
		std::string		_nickname;
		std::string		_phonenumber;
		std::string		_darkestsecret;

		std::string	get_input(void);
		std::string	formatversion(std::string);
		void		set_firstname(void);
		void		set_lastname(void);
		void		set_nickname(void);
		void		set_phonenumber(void);
		void		set_darkestsecret(void);
};

#endif