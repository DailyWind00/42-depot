/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallais <mgallais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:50:17 by mgallais          #+#    #+#             */
/*   Updated: 2024/07/09 10:16:30 by mgallais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Canonical Form :
Cat::Cat()
{
	std::cout << "[Cat] Default Constructor called\n";
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat( const Cat &cat )
{
	std::cout << "[Cat] Copy Constructor called\n";
	this->type = cat.type;
	this->brain = new Brain(*cat.brain);
}

Cat & Cat::operator=( const Cat &cat )
{
	std::cout << "[Cat] Copy assignment operator called\n";
	if (this != &cat) {
		*this->brain = *cat.brain;
		this->type = cat.type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called\n";
	delete this->brain;
}
// ---



// Utility Function :
void Cat::makeSound( void ) const
{
	std::cout << "Meow Meow\n";
}
// ---
