/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:12:39 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/10 11:57:10 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Canonical Form :
Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const &toCopy) : AMateria(toCopy)
{
}

Ice::~Ice()
{
}
// ---



// Utility Function :
AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << AQUA;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	std::cout << RESET;
}
// ---