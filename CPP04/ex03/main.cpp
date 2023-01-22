/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:05:31 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/22 13:03:29 by wmardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main(void)
{
	std::string partition(50, '-');
	
	std::cout << partition << std::endl;
	std::cout << "Subject tests" << std::endl;
	std::cout << partition << std::endl;
	
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	
	std::cout << partition << std::endl;
	std::cout << "Additional tests 1" << std::endl;
	std::cout << partition << std::endl;
	{
		Character newBoi("newBoi");
		Character oldBoi("oldBoi");
		ICharacter& oldBoiref = oldBoi;
		MateriaSource matSrc;
		
		AMateria * materia;
		materia = matSrc.createMateria("knudel");
		
		newBoi.equip(materia);
		newBoi.use(0, oldBoiref);
		
		
		materia = matSrc.createMateria("Ice");
		materia = matSrc.createMateria("ice");
		
		Ice ice;
		
		matSrc.learnMateria(&ice);
		
		AMateria * materia_2;
		materia_2 = matSrc.createMateria("Ice");
		materia_2 = matSrc.createMateria("ice");

		newBoi.equip(materia_2);
		newBoi.use(0, oldBoiref);
		
		
	}
	std::cout << partition << std::endl;
	std::cout << "Additional tests 2" << std::endl;
	std::cout << partition << std::endl;
	{
		IMateriaSource *icesrc = new MateriaSource();
		MateriaSource mixedsrc;
		for (int i = 0; i < 4; i++)
			icesrc->learnMateria(new Ice());
		mixedsrc.learnMateria(new Ice());
		mixedsrc.learnMateria(new Cure());
		mixedsrc.learnMateria(new Ice());
		mixedsrc.learnMateria(new Cure());
		icesrc->learnMateria(new Ice());
		mixedsrc.learnMateria(new Ice());
		MateriaSource mixedsrc2(mixedsrc);
		MateriaSource mixedsrc3;
		mixedsrc3 = mixedsrc2;
		ICharacter *phil = new Character("phil");
		Character bob("bob");
		Character bobcopy;
		phil->use(0, bob);
		bob.use(0, *phil);
		bob.equip(mixedsrc3.createMateria("ice"));
		bob.equip(mixedsrc3.createMateria("cure"));
		bob.equip(mixedsrc3.createMateria("ultima"));
		AMateria *tmp;
		for (int i = 0; i < 5; i++)
		{
			tmp = mixedsrc.createMateria("cure");
			bobcopy.equip(tmp);
		}
		delete tmp;
		bobcopy = bob;
		bob.equip(NULL);
		bob.use(0, *phil);
		bob.use(1, *phil);
		tmp = bob.getMatAddr(0);
		bob.unequip(0);
		bob.unequip(5);
		bob.use(0, *phil);
		delete tmp;
		delete icesrc;
		delete phil;
	}


	return 0;
}
