/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:50:17 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 09:35:51 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Canonical Form :
WrongCat::WrongCat()
{
	std::cout << "[WrongCat] Default Constructor called\n";
	this->type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &wrongCat )
{
	std::cout << "[WrongCat] Copy Constructor called\n";
	*this = wrongCat;
}

WrongCat & WrongCat::operator=( const WrongCat &wrongCat )
{
	std::cout << "[WrongCat] Copy assignment operator called\n";
	if (this != &wrongCat) {
		WrongAnimal::operator=(wrongCat);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor called\n";
}
// ---



// Utility Function :
void WrongCat::makeSound( void ) const
{
	std::cout << "WRONG Meow Meow\n";
}
// ---
