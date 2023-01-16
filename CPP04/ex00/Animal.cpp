/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:18:41 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/16 20:20:35 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal standard constructor called" << std::endl;
}

Animal::Animal(Animal const & src)
{
    *this = src;
}

Animal Animal::operator=(Animal const & rhs)
{
    
}