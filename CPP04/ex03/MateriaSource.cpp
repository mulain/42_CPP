/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:40:07 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/21 20:45:36 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	*this = src;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		if (src._inventory[i])
			_inventory[i] = src._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	//guard vs NULL? prolly not necessary...
	//delete materia? or in main?
	int i = 0;

	while (i < 4 && _inventory[i])
		i++;
	if (i == 4)
		std::cout << "Inventory is full!" << std::endl;
	else
		_inventory[i] = materia->clone();
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4 && _inventory[i] && _inventory[i]->getType() != type)
		i++;
	if (i == 4 || !_inventory[i])
	{
		std::cout << "Unknown Materia type, cannot create it!" << std::endl;
		return NULL;
	}
	return _inventory[i]->clone();
}