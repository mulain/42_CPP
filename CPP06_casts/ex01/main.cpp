/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:50:44 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/31 17:47:00 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

typedef struct Datastruct
{
	int				i;
	char			c;
	std::string		message;
} Data;

uintptr_t serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

int main (void)
{
	Data		data;
	Data*		data_copy;
	uintptr_t	intptr;
	
	data.i = 42;
	data.c = 'a';
	data.message = "mulain was here.";
	
	std::cout << "Address of data: " << &data << ", data.i: " << data.i << ", data.c: " << data.c << ", data.message: " << data.message << std::endl;
	intptr = serialize(&data);
	std::cout << "intptr: " << intptr << ", intptr in hex: 0x" << std::hex << intptr << std::dec << std::endl;
	data_copy = deserialize(intptr);
	std::cout << "data_copy points to: " << data_copy << ", data_copy->i: " << data_copy->i << ", data_copy->c: " << data_copy->c << ", data_copy->message: " << data_copy->message << std::endl;
	
	return 0;
}
