/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:44:24 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/21 12:15:26 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void):
	_name("Unnamed")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character::Character(std::string name):
	_name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	*this = src;
}

Character & Character::operator=(Character const & src)
{
	_name = src._name + "_copy";
	for (int i= 0; i < 4; i++)
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

std::string const & Character::getName(void) const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Cannot equip materia of type NULL!" << std::endl;
		return;
	}
	int i = 0;
	while (i < 4 && _inventory[i])
		i++;
	if (i == 4)
		std::cout << "Inventory is full, cannot equip new materia!" << std::endl;
	else
	{
		_inventory[i] = m;
		std::cout << "New materia equipped in slot " << i << "!"<< std::endl;
	}
 }

 void Character::unequip(int idx)
 {
	if (!_inventory[idx])
		std::cout << "Inventory slot is already empty!" << std::endl;
	else
	{
		_inventory[idx] = NULL;
		std::cout << "Inventory slot " << idx << " cleared!" << std::endl;
	}
 }

 void Character::use(int idx, ICharacter & target)
 {
	if (idx < 0 || idx > 3)
		std::cout << "Invalid inventory slot!" << std::endl;
	else if (!_inventory[idx])
		std::cout << "Inventory slot is empty!" << std::endl;
	else
		_inventory[idx]->use(target);
 }

 AMateria * Character::getMatAddr(int idx) const
 {
	return _inventory[idx];
 }