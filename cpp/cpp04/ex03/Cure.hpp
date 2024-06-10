/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:12:26 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/10 11:50:18 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		// Canonical Form :
		Cure();
		Cure(Cure const &toCopy);
		// Cure &operator=(Cure const &toCopy); // Not needed
		virtual ~Cure();

		// Utility Function :
		AMateria *clone() const;
		void use(ICharacter &target);
};;