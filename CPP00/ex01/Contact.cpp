/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:39:34 by wmardin           #+#    #+#             */
/*   Updated: 2022/12/30 20:19:25 by wmardin          ###   ########.fr       */
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
	return;
}

Contact::~Contact(void)
{
	return;
}

/* void Contact::set_field(Contact::fieldtype field, std::string input)
{
	if (field = fieldtype::firstname)
		this->firstname = input;
	if (field = fieldtype::lastname)
		this->lastname = input;
	if (field = fieldtype::nickname)
		this->nickname = input;
	if (field = fieldtype::phonenumber)
		this->phonenumber = input;
	if (field = fieldtype::darkestsecret)
		this->darkestsecret = input;
} */
