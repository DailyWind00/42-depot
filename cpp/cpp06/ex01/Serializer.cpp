/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:38:07 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 16:01:38 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Canonical Form :
Serializer::Serializer()
{
}

Serializer::Serializer( const Serializer &toCopy )
{
	*this = toCopy;
}

Serializer & Serializer::operator=( const Serializer &toCopy )
{
	(void)toCopy;
	return *this;
}

Serializer::~Serializer()
{
}
// ---



// Utility Function :
uintptr_t	Serializer::serialize( Data* ptr )
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* 		Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data *>(raw);
}
// ---
