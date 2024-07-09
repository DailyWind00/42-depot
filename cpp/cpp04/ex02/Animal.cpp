/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:47 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 10:23:20 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Canonical Form :
Animal::Animal()
{
	std::cout << "[Animal] Default Constructor called\n";
	this->type = "Animal";
}

Animal::Animal( const Animal &animal )
{
	std::cout << "[Animal] Copy Constructor called\n";
	*this = animal;
}

Animal & Animal::operator=( const Animal &animal )
{
	std::cout << "[Animal] Copy assignment operator called\n";
	this->type = animal.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "[Animal] Destructor called\n";
}
// ---



// Utility Function :
void Animal::makeSound( void ) const
{
	std::cout << "Some generic animal sound\n";
}
// ---



// Getters & Setters
std::string	Animal::getType( void ) const
{
	return this->type;
}
// ---