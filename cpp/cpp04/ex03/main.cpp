/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:50:36 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/10 14:13:15 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Fire.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	AMateria* tmp2;

	// equip null materia (error)
	me->equip(NULL);

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp2 = tmp->clone();
	
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	
	tmp = src->createMateria("ice");
	me->equip(tmp2);

	// +4 equiped materia (error)
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	me->unequip(0);

	// use unequiped materia (error)
	me->use(0, *bob);
	me->unequip(0);

	delete bob;
	delete me;
	delete src;
	delete tmp;

	return 0;
}

