/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:25:42 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/30 10:15:03 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

#define E_BLANK "phonebook: field may not be blank. "

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		enum fieldtype
		{
			firstname,
			lastname,
			nickname,
			phonenumber,
			darkestsecret
		};

		void set_field(Contact::fieldtype, std::string);

		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string firstname;
		std::string phonenumber;
		std::string darkestsecret;

	private:
};

#endif