/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:25:42 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/30 21:05:53 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

#define FIRSTNAME	0
#define LASTNAME	1
#define NICKNAME	2
#define PHONENUMBER	3
#define SECRET		4

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
	private:
};

#endif