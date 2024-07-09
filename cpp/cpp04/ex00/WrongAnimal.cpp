/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:49:47 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 09:36:07 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Canonical Form :
WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal] Default Constructor called\n";
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( const WrongAnimal &wrongAnimal )
{
	std::cout << "[WrongAnimal] Copy Constructor called\n";
	*this = wrongAnimal;
}

WrongAnimal & WrongAnimal::operator=( const WrongAnimal &wrongAnimal )
{
	std::cout << "[WrongAnimal] Copy assignment operator called\n";
	if (this != &wrongAnimal) {
		this->type = wrongAnimal.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] Destructor called\n";
}
// ---



// Utility Function :
void WrongAnimal::makeSound( void ) const
{
	std::cout << "Some WRONG generic animal sound\n";
}
// ---



// Getters & Setters
std::string	WrongAnimal::getType( void ) const
{
	return this->type;
}
// ---