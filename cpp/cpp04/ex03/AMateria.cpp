/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 09:55:10 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/21 11:32:14 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Canonical Form :
AMateria::AMateria() : type("default")
{
}

AMateria::AMateria( const AMateria &toCopy ) : type(toCopy.type)
{
}

AMateria::~AMateria()
{
}
// ---



// Utility Function :
void AMateria::use( ICharacter & target )
{
	std::cout << "You have no Materia to use on " << target.getName() << std::endl;
}
// ---



// Specifics Constructors :
AMateria::AMateria( std::string const & type ) : type(type)
{
}
// ---



// Getters and Setters :
std::string const & AMateria::getType( void ) const
{
	return this->type;
}
// ---