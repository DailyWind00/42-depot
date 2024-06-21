/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:13:30 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 11:38:38 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materias[3]; // 3 is the maximum number of materias
	public:
		// Canonical Form :
		MateriaSource();
		MateriaSource(MateriaSource const &toCopy);
		MateriaSource &operator=(MateriaSource const &toCopy);
		~MateriaSource();

		// Utility Function :
		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);

};