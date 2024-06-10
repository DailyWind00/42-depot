/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:13:38 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/10 13:59:17 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Canonical Form :
MateriaSource::MateriaSource()
{
	for (int i = 0; i < 3; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &toCopy)
{
	for (int i = 0; i < 3; i++)
	{
		if (toCopy.materias[i] != NULL)
			materias[i] = toCopy.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &toCopy)
{
	if (this != &toCopy)
	{
		for (int i = 0; i < 3; i++)
		{
			if (materias[i] != NULL)
				delete materias[i];
			if (toCopy.materias[i] != NULL)
				materias[i] = toCopy.materias[i]->clone();
			else
				materias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 3; i++)
		if (materias[i] != NULL)
			delete materias[i];
}
// ---



// Utility Function :
void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 3; i++)
	{
		if (materias[i] == NULL)
		{
			materias[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 3; i++)
	{
		if (materias[i] != NULL && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return NULL;
}
// ---