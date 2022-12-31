/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:39:34 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/31 15:36:44 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->fields[FIRSTNAME].name = "first name";
	this->fields[LASTNAME].name = "last name";
	this->fields[NICKNAME].name = "nick name";
	this->fields[PHONENUMBER].name = "phone number";
	this->fields[SECRET].name = "darkest secret";
}

Contact::~Contact(void)
{
	return;
}