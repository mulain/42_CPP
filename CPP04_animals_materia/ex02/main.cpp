/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:00 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/22 11:53:35 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::string partition(50, '-');
	std::cout << partition << std::endl;
	std::cout << "Scope 1: Cats and Dogs don't care - " << std::endl;
	std::cout << partition << std::endl;
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;
	Dog doggo;
	Cat catto;
	}
	
	std::cout << partition << std::endl;
	std::cout << "Scope 2: but pure Animals can no longer be there!" << std::endl;
	std::cout << partition << std::endl;
	{
		//Animal velociraptor;
	}
	return 0;
}
