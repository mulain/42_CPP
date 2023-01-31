/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:50:44 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/31 18:10:30 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	srand(time(NULL));
	int i = rand();
	if (i % 3 == 0)
	{
		std::cout << "Creating derived class: A" << std::endl;
		return new A;
	}
	if (i % 3 == 1)
	{
		std::cout << "Creating derived class: B" << std::endl;
		return new B;
	}
	if (i % 3 == 2)
	{
		std::cout << "Creating derived class: C" << std::endl;
		return new C;
	}
	std::cout << "This shouldn't happen." << std::endl;
	return NULL;
}

void identify(Base* p)
{
	A*	try_a = dynamic_cast<A*>(p);
	B*	try_b = dynamic_cast<B*>(p);
	C*	try_c = dynamic_cast<C*>(p);

	std::cout << "Pointer dynamic cast identified derived class: ";
	if (try_a)
		std::cout << "A" << std::endl;
	if (try_b)
		std::cout << "B" << std::endl;
	if (try_c)
		std::cout << "C" << std::endl;
}

/* void identify(Base& p)
{
	

	
} */

int main(void)
{
	Base*	ptr = generate();
	//Base&	ref = *ptr;
	
	identify(ptr);
	//identify(ref);
	
	delete ptr;
	return 0;
}
