/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:45:47 by mgallais          #+#    #+#             */
/*   Updated: 2024/06/24 15:52:16 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Canonical Form :
Data::Data()
{
}

Data::Data( const Data &toCopy )
{
	*this = toCopy;
}

Data & Data::operator=( const Data &toCopy )
{
	this->value = toCopy.value;
	return *this;
}

Data::~Data()
{
}
// ---



// Specifics Constructors :
Data::Data( int val ) : value(val)
{
}
// ---



// Getters and Setters :
void Data::setValue( int newValue )
{
	this->value = newValue;
}

int Data::getValue() const
{
	return this->value;
}
// ---
