/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:00 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/22 11:51:36 by wmardin          ###   ########.fr       */
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
	std::cout << "Scope 2: Proof of deep copy" << std::endl;
	std::cout << partition << std::endl;
	{
		Cat a;
		Cat b(a);

		std::cout << a.getIdea(1) << std::endl;
		std::cout << b.getIdea(1) << std::endl;
		a.setIdea(1, "Annoy my human.");
		b.setIdea(1, "Push stuff off of the coffee table.");
		std::cout << a.getIdea(1) << std::endl;
		std::cout << b.getIdea(1) << std::endl;
		b = a;
		std::cout << b.getIdea(1) << std::endl;
		
	}
	
	std::cout << partition << std::endl;
	std::cout << "Scope 3: Deleting Cats and Dogs as Animals" << std::endl;
	std::cout << partition << std::endl;
	{
		Animal *zoo[10];
		for (int i = 0; i < 5; i++)
		{
			zoo[i] = new Cat;
			zoo[i + 5] = new Dog;
		}
		zoo[1]->makeSound();
		zoo[5]->makeSound();
		for (int i = 0; i < 10; i++)
			delete zoo[i];
	}
	return 0;
}
