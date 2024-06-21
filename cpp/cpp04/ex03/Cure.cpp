/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:12:33 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 11:32:19 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Canonical Form :
Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &toCopy) : AMateria(toCopy)
{
}

Cure::~Cure()
{
}
// ---



// Utility Function :
AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << YELLOW;
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
	std::cout << RESET;
}
// ---