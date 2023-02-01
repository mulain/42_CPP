/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:50:44 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/01 10:35:12 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*
dynamic_cast is a type of casting operator that allows for type-safe, runtime type checking
of objects.
It is typically used when you have a pointer or reference to a base class and need to convert
it to a derived class, but you want to make sure at runtime that the object actually is
of the derived class type.
If the conversion is not possible, dynamic_cast returns a null pointer or a reference
to a nullptr, indicating that the conversion failed.

Note that dynamic_cast only works with polymorphic types, that is, classes with virtual functions.
*/

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

void identify(Base& p)
{
	Base	base;
	
	std::cout << "Reference dynamic cast identified derived class: ";
	try
	{
		base = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		base = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;

	}
	catch(const std::exception& e)
	{
	}
	try
	{
		base = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;

	}
	catch(const std::exception& e)
	{
	}
}

int main(void)
{
	Base*	ptr = generate();
	Base&	ref = *ptr;
	
	identify(ptr);
	identify(ref);
	
	delete ptr;
	return 0;
}
