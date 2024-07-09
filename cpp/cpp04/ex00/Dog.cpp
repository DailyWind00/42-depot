/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:50:03 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 09:36:19 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Canonical Form :
Dog::Dog()
{
	std::cout << "[Dog] Default Constructor called\n";
	this->type = "Dog";
}

Dog::Dog( const Dog &dog )
{
	std::cout << "[Dog] Copy Constructor called\n";
	*this = dog;
}

Dog & Dog::operator=( const Dog &dog )
{
	std::cout << "[Dog] Copy assignment operator called\n";
	if (this != &dog) {
		*static_cast<Animal *>(this) = dog;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called\n";
}
// ---



// Utility Function :
void Dog::makeSound( void ) const
{
	std::cout << "Wouf Wouf\n";
}
// ---
