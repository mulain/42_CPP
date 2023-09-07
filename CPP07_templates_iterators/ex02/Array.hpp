/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:17:57 by wmardin           #+#    #+#             */
/*   Updated: 2023/02/05 18:00:41 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
