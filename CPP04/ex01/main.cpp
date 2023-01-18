/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:00 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 11:47:31 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	std::string partition(50, '-');
	
	std::cout << partition << std::endl;
	std::cout << "Scope 1: Subject test" << std::endl;
	std::cout << partition << std::endl;
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; //should not create a leak
	delete i;
	}
	
	std::cout << partition << std::endl;
	std::cout << "Scope 2: More tests" << std::endl;
	std::cout << partition << std::endl;
	{
		Cat a;
		
		Cat b(a);
		
	}
	return 0;
}