/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:25:42 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/30 20:19:36 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H
#define FIRSTNAME	0
#define LASTNAME	1
#define NICKNAME	2
#define PHONENUMBER	3
#define SECRET		4

#include <iostream>

#define E_BLANK "phonebook: field may not be blank. "

struct Field
{
	std::string	name;
	std::string	value;
};

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		Field	fields[5];

		/* std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string firstname;
		std::string phonenumber;
		std::string darkestsecret; */

	private:
};

#endif