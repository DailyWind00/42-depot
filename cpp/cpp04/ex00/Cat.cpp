/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:50:17 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 09:36:28 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Canonical Form :
Cat::Cat()
{
	std::cout << "[Cat] Default Constructor called\n";
	this->type = "Cat";
}

Cat::Cat( const Cat &cat )
{
	std::cout << "[Cat] Copy Constructor called\n";
	*this = cat;
}

Cat & Cat::operator=( const Cat &cat )
{
	std::cout << "[Cat] Copy assignment operator called\n";
	if (this != &cat) {
		*static_cast<Animal *>(this) = cat;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called\n";
}
// ---



// Utility Function :
void Cat::makeSound( void ) const
{
	std::cout << "Meow Meow\n";
}
// ---
