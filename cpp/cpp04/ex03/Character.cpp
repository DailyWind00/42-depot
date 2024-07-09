/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:12:56 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 10:27:50 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Canonical Form :
Character::Character()
{
	name = "You";
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

Character::Character( Character const & toCopy )
{
	name = toCopy.name;
	for (int i = 0; i < 4; i++)
	{
		if (toCopy.materias[i])
			materias[i] = toCopy.materias[i]->clone(); // Deep copy because clone use new
		else
			materias[i] = NULL;
	}
}

Character & Character::operator=( Character const & toCopy )
{
	if (this != &toCopy)
	{
		name = toCopy.name;
		for (int i = 0; i < 4; i++)
		{
			if (materias[i])
				delete materias[i];
			if (toCopy.materias[i])
				materias[i] = toCopy.materias[i]->clone(); // Deep copy because clone use new
			else
				materias[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (materias[i])
			delete materias[i];
}
// ---



// Specifics Constructors :
Character::Character( std::string const & name )
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}
// ---



// Utility Function :
void Character::equip( AMateria* m )
{
	if (!m)
	{
		std::cout << "You can't equip a NULL materia\n";
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			std::cout << "You equip the materia " << m->getType() << std::endl;
			materias[i] = m;
			return;
		}
	}
	std::cout << "You can't equip more than 4 materias\n";
}

void Character::unequip( int idx )
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Unequip : invalid index\n";
		return;
	}
	if (!materias[idx])
	{
		std::cout << "You can't unequip a materia that doesn't exist\n";
		return;
	}
	std::cout << "You unequip the materia " << materias[idx]->getType() << std::endl;
	delete materias[idx];
	materias[idx] = NULL;
}

void Character::use( int idx, ICharacter& target )
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << "Use : invalid index\n";
		return;
	}
	if (!materias[idx])
	{
		std::cout << "You can't use a materia that doesn't exist\n";
		return;
	}
	materias[idx]->use(target);
}
// ---



// Getters and Setters :
std::string const & Character::getName() const
{
	return name;
}
// ---