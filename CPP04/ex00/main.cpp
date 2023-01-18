/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:00 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/18 10:04:32 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::string partition(50, '-');
	
	std::cout << partition << std::endl;
	std::cout << "Scope 1: Subject" << std::endl;
	std::cout << partition << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	std::cout << partition << std::endl;
	std::cout << "Scope 2: WrongAnimal" << std::endl;
	std::cout << partition << std::endl;
	{
		WrongAnimal wrongA;

		std::cout << wrongA.getType() << std::endl;
		wrongA.makeSound();

		WrongAnimal* wrongcat = new WrongCat;

		wrongcat->getType();
		wrongcat->makeSound();
		delete wrongcat;
	}
	return 0;
}
