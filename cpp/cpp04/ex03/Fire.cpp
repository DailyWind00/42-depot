/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:44:29 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/10 11:56:35 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"

// Canonical Form :
Fire::Fire() : AMateria("fire")
{
}

Fire::Fire(Fire const &toCopy) : AMateria(toCopy)
{
}

Fire::~Fire()
{
}
// ---



// Utility Function :
AMateria *Fire::clone() const
{
	return new Fire(*this);
}

void Fire::use(ICharacter &target)
{
	std::cout << RED;
	std::cout << "* burns " << target.getName() << " with fire *" << std::endl;
	std::cout << RESET;
}
// ---