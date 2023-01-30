/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:05:31 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/30 12:18:41 by wmardin          ###   ########.fr       */
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
		
		AMateria * materia = NULL;
		
		std::cout << "Equipping NULL materia:" << std::endl;
		newBoi.equip(materia);

		std::cout << std::endl << "Using empty inventory slot:" << std::endl;
		newBoi.use(0, oldBoiref);
		
		std::cout << std::endl << "Creating new Materia from string (but none learned yet):" << std::endl;
		materia = matSrc.createMateria("Ice");
		materia = matSrc.createMateria("ice");
		
		
		std::cout << std::endl << "Learning new Materia from ice object:" << std::endl;
		matSrc.learnMateria(new Ice);
		
		std::cout << std::endl << "Creating new Materia from string (ice learned):" << std::endl;
		AMateria * materia_2;
		materia_2 = matSrc.createMateria("Ice");
		materia_2 = matSrc.createMateria("ice");
		
		std::cout << std::endl << "Equipping new Materia and using:" << std::endl;
		newBoi.equip(materia_2);
		newBoi.use(0, oldBoiref);		
	}
	std::cout << partition << std::endl;
	std::cout << "Additional tests 2" << std::endl;
	std::cout << partition << std::endl;
	{
		IMateriaSource *icesrc = new MateriaSource();
		MateriaSource mixedsrc;
		std::cout << std::endl << "Filling icesrc" << std::endl;
		for (int i = 0; i < 4; i++)
			icesrc->learnMateria(new Ice());
		icesrc->learnMateria(new Ice());

		std::cout << std::endl << "Filling mixedsrc" << std::endl;
		mixedsrc.learnMateria(new Ice());
		mixedsrc.learnMateria(new Cure());
		mixedsrc.learnMateria(new Ice());
		mixedsrc.learnMateria(new Cure());
		mixedsrc.learnMateria(new Ice());
		
		std::cout << std::endl << "Copying mixedsrc" << std::endl;
		MateriaSource mixedsrc2(mixedsrc);
		MateriaSource mixedsrc3;
		mixedsrc3 = mixedsrc2;

		std::cout << std::endl << "Messing around with Characters" << std::endl;
		ICharacter *phil = new Character("phil");
		Character bob("bob");
		
		phil->use(0, bob);
		bob.use(0, *phil);
		std::cout << std::endl;
		std::cout << "Equipping and reequipping bob" << std::endl;
		AMateria* icemat = mixedsrc.createMateria("ice");
		bob.equip(icemat);
		bob.equip(icemat);
		bob.equip(icemat);
		bob.equip(icemat);
		bob.equip(icemat);
		bob.unequip(2);
		bob.equip(icemat);
		std::cout << std::endl;

		std::cout << "Messing around some more" << std::endl;
		AMateria *tmp;
		bob.equip(NULL);
		bob.use(0, *phil);
		bob.use(1, *phil);
		bob.equip(mixedsrc3.createMateria("cure"));
		tmp = bob.getMatAddr(0);
		bob.unequip(0);
		bob.unequip(5);
		bob.unequip(2);
		bob.use(0, *phil);
		std::cout << "testy\n" << std::endl;
		delete tmp;
		delete icesrc;
		delete phil;
		delete icemat;
	}
	return 0;
}
