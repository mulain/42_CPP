/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:17:57 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/03 17:55:55 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Turn-in directory : ex02/
Files to turn in : Makefile, main.cpp, Array.{h, hpp}
and optional file: Array.tpp
Forbidden functions : None

Develop a class template Array that contains elements of type T and that implements
the following behavior and functions:
• Construction with no parameter: Creates an empty array.
• Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
Tip: Try to compile int * a = new int(); then display *a.
• Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
• You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
• Elements can be accessed through the subscript operator: [ ].
• When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
• A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance.
As usual, ensure everything works as expected and turn in a main.cpp file that contains your tests.
8

*/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		// Constructors
		Array(void):
			_size(0),
			_content(new T[_size])
		{}
		Array(unsigned int n):
			_size(n),
			_content(new T[_size])
		{}
		Array(const Array& src)
		{
			*this = src;
		}
		
		// Destructors
		~Array(void)
		{
			delete[] _content;
		}
		
		// Operator overloads
		Array& operator=(const Array& src)
		{
			_size = src._size;
			delete[] _content;
			_content = new T[_size];
			for (size_t i = 0; i < _size; i++)
				_content[i] = src._content[i];
			return *this;			
		}

		T& operator[](size_t index)
		{
			checkIndex(index);
			return _content[index];
		}
		
		// Getters
		size_t getSize(void)
		{
			return _size;
		}

		T getElement(size_t index)
		{
			checkIndex(index);
			return _content[index];
		}

		// Setters
		void setElement(size_t index, T value)
		{
			checkIndex(index);
			_content[index] = value;
		}
	
	private:
		// Checkers
		void checkIndex(size_t index)
		{
			if (index >= _size)
				throw std::out_of_range("Invalid index.");
		}
		
		// Attributes
		size_t	_size;
		T*		_content;
};

#endif
