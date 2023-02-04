/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:17:57 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/04 18:51:43 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

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
		size_t getSize(void) const
		{
			return _size;
		}
	
	private:
		// Checkers
		void checkIndex(size_t index) const
		{
			if (index >= _size)
				throw std::out_of_range("Invalid index.");
		}
		
		// Attributes
		size_t	_size;
		T*		_content;
};

#endif
