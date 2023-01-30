/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmardin <wmardin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:05:31 by wmardin           #+#    #+#             */
/*   Updated: 2023/01/30 20:19:03 by wmardin          ###   ########.fr       */
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

		ICharacter* bert = new Character("bert");

		me->use(0, *bert);
		me->use(1, *bert);

		delete bert;
		delete me;
		delete src;
	}
	
	std::cout << partition << std::endl;
	std::cout << "Additional tests 1: Inventory / Learning Materia" << std::endl;
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
	std::cout << "Additional tests 2: Materia Sources" << std::endl;
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
		
		delete icesrc;
	}

	std::cout << partition << std::endl;
	std::cout << "Additional tests 3: Characters / more Inventory" << std::endl;
	std::cout << partition << std::endl;
	{

		std::cout << std::endl << "Messing around with Characters" << std::endl;
		ICharacter*		ernie = new Character("ernie");
		Character		bert("bert");
		MateriaSource	matSource;
		
		ernie->use(0, bert);
		bert.use(0, *ernie);
		std::cout << std::endl;
		std::cout << "Equipping and reequipping bert" << std::endl;
		matSource.learnMateria(new Ice);
		// These don't have to be deleted as long as they are in a character inventory
		// when the scope ends. If they are not equipped, have to manually delete.
		AMateria* icemat0 = matSource.createMateria("ice");
		AMateria* icemat1 = matSource.createMateria("ice");
		AMateria* icemat2 = matSource.createMateria("ice");
		AMateria* icemat3 = matSource.createMateria("ice");
		bert.equip(icemat0);
		bert.equip(icemat1);
		bert.equip(icemat2);
		bert.equip(icemat3);
		bert.equip(icemat3);
		bert.unequip(2);
		bert.equip(icemat2);
		bert.unequip(5);
		std::cout << std::endl;

		std::cout << "Messing around some more" << std::endl;
		bert.equip(NULL);
		bert.use(0, *ernie);
		bert.use(1, *ernie);
		bert.equip(matSource.createMateria("cure"));
		std::cout << std::endl;

		std::cout << "Unequipping and not leaking (getMatAddr)" << std::endl;
		
		AMateria* tmp;
		
		tmp = bert.getMatAddr(0);
		bert.unequip(0);
		delete tmp;
		bert.use(0, *ernie);
		
		tmp = bert.getMatAddr(2);
		bert.unequip(2);
		delete tmp;

		// Don't have to getMatAddr if you know exactly which pointer was 
		// equipped in the slot that was unequipped.
		bert.unequip(3);
		delete icemat3;
		
		delete ernie;
	}
	std::cout << "End of tests." << std::endl;
	return 0;
}
